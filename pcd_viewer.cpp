//#include <iostream>
//#include <pcl/io/pcd_io.h>
//#include <pcl/visualization/cloud_viewer.h>
//
//int main()
//{
//    std::string file_path = "E:\\pcl\\data\\output.pcd";
//    // 提示用户输入文件路径
//    std::cout << "Enter the absolute path of your PCD file: ";
//    std::getline(std::cin, file_path);
//
//    // 读取PCD文件
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    if (pcl::io::loadPCDFile<pcl::PointXYZ>(file_path, *cloud) == -1)
//    {
//        std::cerr << "Couldn't read file" << std::endl;
//        return -1;
//    }
//
//    // 创建一个可视化对象
//    pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
//    viewer.showCloud(cloud);
//
//    // 保持窗口打开，直到用户关闭
//    while (!viewer.wasStopped())
//    {
//    }
//
//    return 0;
//}
