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
    // 创建点云对象
    pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>());

    // 打开LAS文件读取器
    LASreadOpener lasReadOpener;
    lasReadOpener.set_file_name(inputFile.c_str());
    LASreader* lasReader = lasReadOpener.open();

    if (!lasReader) {
        std::cerr << "无法打开LAS文件" << std::endl;
        return;
    }

    // 读取LAS文件
    while (lasReader->read_point()) {
        cloud->push_back(pcl::PointXYZ(lasReader->point.get_x(), lasReader->point.get_y(), lasReader->point.get_z()));
    }

    // 关闭LAS文件读取器
    lasReader->close();
    delete lasReader;

    std::cout << "读取LAS文件完成，共有 " << cloud->points.size() << " 个点。" << std::endl;

    // 检查点云是否为空
    if (cloud->points.empty()) {
        std::cerr << "点云数据为空。" << std::endl;
        return;
    }

    // 创建一个PassThrough滤波器，过滤掉指定范围内的点
    pcl::PointCloud<PointT>::Ptr filtered_cloud(new pcl::PointCloud<PointT>());
    pcl::PassThrough<PointT> pass;
    pass.setInputCloud(cloud);
    pass.setFilterFieldName("z"); // 根据z轴过滤
    pass.setFilterLimits(-2.699, -0.378); // 设置过滤范围
    pass.filter(*filtered_cloud);

    std::cout << "过滤完成，剩余 " << filtered_cloud->points.size() << " 个点。" << std::endl;

    // 保存滤波后的点云到PCD文件
    if (pcl::io::savePCDFileBinary(outputFile, *filtered_cloud) == -1) {
        PCL_ERROR("保存PCD文件失败。\n");
    }
    else {
        std::cout << "已保存滤波后的点云到 " << outputFile << std::endl;
    }

    // 可视化过滤后的点云
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
    std::string outputFile = "E:\\pcl\\data\\output_filtered.pcd"; // 设置输出文件名
    filterPointCloud(inputFile, outputFile);

    return 0;
}
