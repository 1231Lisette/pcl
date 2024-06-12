//#include <iostream>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
//#include <pcl/filters/statistical_outlier_removal.h> // 添加头文件
//#include <lasreader.hpp>
//
//int main(int argc, char** argv)
//{
//     Create point cloud data
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//
//     Open LAS file reader
//    LASreadOpener lasReadOpener;
//    lasReadOpener.set_file_name("E:\\pcl\\data\\MANIFOLD_2024-4-8-10-48-45-Cloud_LAS.las");
//    LASreader* lasReader = lasReadOpener.open();
//
//    if (!lasReader)
//    {
//        std::cerr << "Could not open LAS file" << std::endl;
//        return -1;
//    }
//
//     Read LAS file
//    while (lasReader->read_point())
//    {
//        cloud->push_back(pcl::PointXYZ(lasReader->point.get_x(), lasReader->point.get_y(), lasReader->point.get_z()));
//    }
//
//     Close LAS file reader
//    lasReader->close();
//    delete lasReader;
//     Statistical outlier removal
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor_outlier;
//    sor_outlier.setInputCloud(cloud);
//    sor_outlier.setMeanK(50);            // Set the number of neighbors to use for mean distance estimation
//    sor_outlier.setStddevMulThresh(1.0); // Set the standard deviation multiplier threshold
//    sor_outlier.filter(*cloud_filtered);
//
//     Calculate point cloud density for each 0.001m height change
//    const float min_z = -3.0; // Minimum height
//    const float max_z = 1.0;  // Maximum height
//    const float height_step = 0.001; // Height step
//    const int num_levels = static_cast<int>((max_z - min_z) / height_step) + 1;
//
//     Initialize density counts
//    std::vector<int> density_counts(num_levels, 0);
//
//     Count points in each height level
//    for (const auto& point : cloud_filtered->points) {
//        int level_index = static_cast<int>((point.z - min_z) / height_step);
//        if (level_index >= 0 && level_index < num_levels) {
//            density_counts[level_index]++;
//        }
//    }
//
//     Output density for each 0.001m height change
//    for (int i = 0; i < num_levels; ++i) {
//        float height = min_z + i * height_step;
//        float density = static_cast<float>(density_counts[i]) / height_step;
//        std::cout << "Height: " << height << " Density: " << density << " points/m" << std::endl;
//    }
//
//    return 0;
//}
