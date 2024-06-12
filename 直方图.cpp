//#include <iostream>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
//#include <pcl/filters/statistical_outlier_removal.h>
//#include <pcl/visualization/pcl_plotter.h>
//#include <lasreader.hpp>
//
//int main()
//{
//    // Create point cloud data
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//
//    // Open LAS file reader
//    LASreadOpener lasReadOpener;
//    lasReadOpener.set_file_name("E:\\pcl\\data\\MANIFOLD_2024-4-18-Cloud_LAS_v.las");
//    LASreader* lasReader = lasReadOpener.open();
//
//    if (!lasReader)
//    {
//        std::cerr << "Could not open LAS file" << std::endl;
//        return -1;
//    }
//
//    // Read LAS file
//    while (lasReader->read_point())
//    {
//        cloud->push_back(pcl::PointXYZ(lasReader->point.get_x(), lasReader->point.get_y(), lasReader->point.get_z()));
//    }
//
//    // Close LAS file reader
//    lasReader->close();
//    delete lasReader;
//
//    // ʹ��ͳ���˲����Ƴ���Ⱥ��
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
//    sor.setInputCloud(cloud);
//    sor.setMeanK(50); // ����ͳ�Ʒ�Χ�ڵ������
//    sor.setStddevMulThresh(1.0); // ���ñ�׼��ı�����ֵ
//    sor.filter(*cloud_filtered);
//
//    // ����ֱ��ͼ
//    pcl::visualization::PCLPlotter plotter;
//    plotter.addFeatureHistogram(*cloud_filtered, "z", 5); // ������������ֱ��ͼ��������
//    plotter.plot();
//
//    return 0;
//}
