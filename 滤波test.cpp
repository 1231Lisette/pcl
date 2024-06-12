//#include <iostream>
//#include <random>
//#include <pcl/point_types.h>
//#include <pcl/point_cloud.h>
//#include <pcl/filters/conditional_removal.h>
//#include <pcl/visualization/pcl_visualizer.h>
//
//int main()
//{
//    // Step 1: 创建点云数据
//    std::random_device rd;
//    std::default_random_engine random(rd());
//    std::uniform_real_distribution<float> dis(0.0f, 3.0f);
//
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    for (int i = 0; i < 3000; ++i)
//    {
//        float x = dis(random);
//        float y = dis(random);
//        float z = dis(random);
//        cloud->points.push_back({ x, y, z });
//    }
//
//    // Step 2: 创建条件滤波对象
//    pcl::ConditionalRemoval<pcl::PointXYZ> conditional_removal(true);
//
//    // Step 3: 设置条件滤波参数
//    // 条件与：保留点云xyz坐标都在[1,2]之内的点
//    pcl::ConditionAnd<pcl::PointXYZ>::Ptr condition_add(new pcl::ConditionAnd<pcl::PointXYZ>());
//    condition_add->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr(new pcl::FieldComparison<pcl::PointXYZ>("z", pcl::ComparisonOps::GE, 1.0)));
//    condition_add->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr(new pcl::FieldComparison<pcl::PointXYZ>("z", pcl::ComparisonOps::LE, 2.0)));
//    condition_add->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr(new pcl::FieldComparison<pcl::PointXYZ>("y", pcl::ComparisonOps::GE, 1.0)));
//    condition_add->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr(new pcl::FieldComparison<pcl::PointXYZ>("y", pcl::ComparisonOps::LE, 2.0)));
//    condition_add->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr(new pcl::FieldComparison<pcl::PointXYZ>("x", pcl::ComparisonOps::GE, 1.0)));
//    condition_add->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr(new pcl::FieldComparison<pcl::PointXYZ>("x", pcl::ComparisonOps::LE, 2.0)));
//
//    // 条件或
//    pcl::ConditionOr<pcl::PointXYZ>::Ptr condition_or(new pcl::ConditionOr<pcl::PointXYZ>());
//    condition_or->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr(new pcl::FieldComparison<pcl::PointXYZ>("z", pcl::ComparisonOps::GE, 2)));
//    condition_or->addComparison(pcl::FieldComparison<pcl::PointXYZ>::ConstPtr(new pcl::FieldComparison<pcl::PointXYZ>("x", pcl::ComparisonOps::GE, 1.5)));
//
//    condition_or->addCondition(condition_add);
//
//    conditional_removal.setCondition(condition_or);
//    conditional_removal.setInputCloud(cloud);
//
//    // Step 4: 执行滤波处理
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
//    conditional_removal.filter(*cloud_filtered);
//
//    // Step 5: 可视化滤波结果
//    pcl::visualization::PCLVisualizer viewer("pcl condition removal filter");
//    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_handler(cloud, 255, 0, 0);
//    viewer.addPointCloud(cloud, cloud_handler, "cloud");
//
//    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> filtered_handler(cloud_filtered, 0, 255, 0);
//    viewer.addPointCloud(cloud_filtered, filtered_handler, "cloud_filtered");
//
//    viewer.addCoordinateSystem(1);
//
//    while (!viewer.wasStopped())
//    {
//        viewer.spinOnce();
//    }
//    viewer.close();
//
//    return 0;
//}
