#include <pcl/io/pcd_io.h>
#include <lasreader.hpp>
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <thread>
#include <chrono>

typedef pcl::PointXYZ PointT;

void filterPointCloud(const std::string& inputFile, const std::string& outputFile)
{
    // �������ƶ���
    pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>());

    // ��LAS�ļ���ȡ��
    LASreadOpener lasReadOpener;
    lasReadOpener.set_file_name(inputFile.c_str());
    LASreader* lasReader = lasReadOpener.open();

    if (!lasReader) {
        std::cerr << "�޷���LAS�ļ�" << std::endl;
        return;
    }

    // ��ȡLAS�ļ�
    while (lasReader->read_point()) {
        cloud->push_back(pcl::PointXYZ(lasReader->point.get_x(), lasReader->point.get_y(), lasReader->point.get_z()));
    }

    // �ر�LAS�ļ���ȡ��
    lasReader->close();
    delete lasReader;

    std::cout << "��ȡLAS�ļ���ɣ����� " << cloud->points.size() << " ���㡣" << std::endl;

    // �������Ƿ�Ϊ��
    if (cloud->points.empty()) {
        std::cerr << "��������Ϊ�ա�" << std::endl;
        return;
    }

    // ����һ��PassThrough�˲��������˵�ָ����Χ�ڵĵ�
    pcl::PointCloud<PointT>::Ptr filtered_cloud(new pcl::PointCloud<PointT>());
    pcl::PassThrough<PointT> pass;
    pass.setInputCloud(cloud);
    pass.setFilterFieldName("z"); // ����z�����
    pass.setFilterLimits(-2.699, -0.378); // ���ù��˷�Χ
    pass.filter(*filtered_cloud);

    std::cout << "������ɣ�ʣ�� " << filtered_cloud->points.size() << " ���㡣" << std::endl;

    // �����˲���ĵ��Ƶ�PCD�ļ�
    if (pcl::io::savePCDFileBinary(outputFile, *filtered_cloud) == -1) {
        PCL_ERROR("����PCD�ļ�ʧ�ܡ�\n");
    }
    else {
        std::cout << "�ѱ����˲���ĵ��Ƶ� " << outputFile << std::endl;
    }

    // ���ӻ����˺�ĵ���
    pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer("Filtered Point Cloud"));
    viewer->setBackgroundColor(0, 0, 0);
    pcl::visualization::PointCloudColorHandlerCustom<PointT> color_handler(filtered_cloud, 255, 255, 255);
    viewer->addPointCloud(filtered_cloud, color_handler, "filtered_cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "filtered_cloud");
    viewer->addCoordinateSystem(1.0);
    viewer->initCameraParameters();

    while (!viewer->wasStopped()) {
        viewer->spinOnce(100);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    std::string inputFile = "E:\\pcl\\data\\MANIFOLD_2024-3-25-10-48-45-Cloud_LAS.las";
    std::string outputFile = "E:\\pcl\\data\\output_filtered.pcd"; // ��������ļ���
    filterPointCloud(inputFile, outputFile);

    return 0;
}
