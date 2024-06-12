//#include <iostream>
//#include <pcl/io/pcd_io.h>
//#include <pcl/visualization/cloud_viewer.h>
//
//int main()
//{
//    std::string file_path = "E:\\pcl\\data\\output.pcd";
//    // ��ʾ�û������ļ�·��
//    std::cout << "Enter the absolute path of your PCD file: ";
//    std::getline(std::cin, file_path);
//
//    // ��ȡPCD�ļ�
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    if (pcl::io::loadPCDFile<pcl::PointXYZ>(file_path, *cloud) == -1)
//    {
//        std::cerr << "Couldn't read file" << std::endl;
//        return -1;
//    }
//
//    // ����һ�����ӻ�����
//    pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");
//    viewer.showCloud(cloud);
//
//    // ���ִ��ڴ򿪣�ֱ���û��ر�
//    while (!viewer.wasStopped())
//    {
//    }
//
//    return 0;
//}
