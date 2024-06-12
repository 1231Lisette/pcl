//#include <iostream>
//#include <vector>
//#include <math.h>  
//#include <pcl/io/pcd_io.h>
//#include <pcl/filters/filter.h>
//#include <pcl/filters/voxel_grid.h>
//#include <pcl/kdtree/kdtree_flann.h>
//#include <pcl/filters/normal_space.h>
//#include <pcl/common/eigen.h>
//#include <pcl/features/normal_3d.h>
//#include <pcl/features/fpfh.h>
//#include <pcl/visualization/pcl_plotter.h>
//#include <pcl/visualization/histogram_visualizer.h>
//
//using namespace std;
//using namespace pcl::visualization;
//using namespace pcl::console;
//
//void generateData(double* ax, double* acos, double* asin, int numPoints)
//{
//    double inc = 7.5 / (numPoints - 1);
//    for (int i = 0; i < numPoints; ++i)
//    {
//        ax[i] = i * inc;
//        acos[i] = cos(i * inc);
//        asin[i] = sin(i * inc);
//    }
//}
//
//int main(int argc, char* argv[])
//{
//    if (argc < 2)
//    {
//        std::cout << "Usage: " << argv[0] << " E:\\pcl\\data\\MANIFOLD_2024-4-18-Cloud_LAS_v.las" << endl;
//        return 0;
//    }
//
//    // 读取点云数据
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_src(new pcl::PointCloud<pcl::PointXYZ>);
//    cout << "Loading point cloud..." << endl;
//    if (pcl::io::loadPCDFile(argv[1], *cloud_src) == -1 || cloud_src->empty())
//    {
//        PCL_ERROR("Couldn't read point cloud %s.\n", argv[1]);
//        return -1;
//    }
//
//    // 检查点云是否为空
//    if (cloud_src->empty())
//    {
//        PCL_ERROR("Point cloud is empty.\n");
//        return -1;
//    }
//
//    cout << "Point cloud loaded successfully." << endl;
//
//    // 计算法向量
//    float voxel_re = 0.005, ds_N = 5;
//    pcl::PointCloud<pcl::PointXYZ>::Ptr ds_src(new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::VoxelGrid<pcl::PointXYZ> grid;
//    grid.setLeafSize(voxel_re, voxel_re, voxel_re);
//    grid.setInputCloud(cloud_src);
//    grid.filter(*ds_src);
//
//    pcl::PointCloud<pcl::Normal>::Ptr norm_src(new pcl::PointCloud<pcl::Normal>);
//    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree_src(new pcl::search::KdTree<pcl::PointXYZ>());
//    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
//    ne.setInputCloud(ds_src);
//    ne.setSearchSurface(cloud_src);
//    ne.setSearchMethod(tree_src);
//    ne.setRadiusSearch(ds_N * 2 * voxel_re);
//
//    // 检查输入点云是否为空
//    if (ds_src->empty())
//    {
//        PCL_ERROR("Downsampled point cloud is empty.\n");
//        return -1;
//    }
//
//    cout << "Computing normals..." << endl;
//
//    // 计算法线
//    ne.compute(*norm_src);
//
//    // 检查法线是否为空
//    if (norm_src->empty())
//    {
//        PCL_ERROR("Computed normals are empty.\n");
//        return -1;
//    }
//
//    cout << "Normals computed successfully." << endl;
//
//    // 计算FPFH特征
//    pcl::FPFHEstimation<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_est_src;
//    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree_fpfh_src(new pcl::search::KdTree<pcl::PointXYZ>());
//    fpfh_est_src.setSearchSurface(ds_src);
//    fpfh_est_src.setInputCloud(ds_src);
//    fpfh_est_src.setInputNormals(norm_src);
//    fpfh_est_src.setRadiusSearch(2 * ds_N * voxel_re);
//    fpfh_est_src.setSearchMethod(tree_fpfh_src);
//    pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfh_src(new pcl::PointCloud<pcl::FPFHSignature33>);
//    fpfh_est_src.compute(*fpfh_src);
//
//    cout << "FPFH features computed successfully." << endl;
//
//    // 创建PCLPlotter对象
//    PCLPlotter* plotter = new PCLPlotter("My Plotter");
//    plotter->setShowLegend(true);
//
//    // 添加FPFH特征直方图
//    plotter->addFeatureHistogram<pcl::FPFHSignature33>(*fpfh_src, "fpfh", 2, "z_fpfh"); // 使用第三个维度作为直方图
//
//    // 设置窗口大小并显示
//    plotter->setWindowSize(1200, 800); // 设置窗口宽度为1200，高度为800
//    plotter->spinOnce(30000000);
//
//    return 0;
//}
