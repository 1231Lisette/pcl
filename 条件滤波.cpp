//#include <iostream>
//#include <pcl/io/io.h>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
//#include <pcl/filters/conditional_removal.h>
//#include <pcl/filters/passthrough.h>
//#include <pcl/visualization/pcl_visualizer.h>
//#include <lasreader.hpp>
//#include <laswriter.hpp> // Add liblas header file
//
//int main(int argc, char** argv)
//{
//    // Create point cloud data
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//
//    // Open LAS file reader
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
//    // Filter out points not within a certain range
//    pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::PassThrough<pcl::PointXYZ> pass;
//    pass.setInputCloud(cloud);
//    pass.setFilterFieldName("z");
//    pass.setFilterLimits(-2.699, -0.378); // Adjust the limits as needed
//    pass.filter(*filtered_cloud);
//
//    // Save filtered point cloud to PCD file
//    //pcl::io::savePCDFileASCII("E:\\pcl\\data\\filtered_cloud.pcd", *filtered_cloud);
//
//    // Visualization of the filtered result
//    pcl::visualization::PCLVisualizer viewer("pcl condition removal filter");
//
//    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_handler(filtered_cloud, 255, 255, 255);
//    viewer.addPointCloud(filtered_cloud, cloud_handler, "cloud");
//
//    viewer.addCoordinateSystem(1);
//
//    while (!viewer.wasStopped())
//    {
//        viewer.spinOnce();
//    }
//
//    return 0;
//}
