#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>

int main(int argc, char** argv) {
    // PCD 파일 경로를 커맨드 라인에서 입력 받기
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_pcd_file>" << std::endl;
        return -1;
    }

    std::string input_pcd_filename = argv[1];

    // PCD 파일 읽기
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(input_pcd_filename, *cloud) == -1) {
        PCL_ERROR("Couldn't read file %s\n", input_pcd_filename.c_str());
        return -1;
    }

    // PLY 파일로 저장 (입력 PCD 파일과 같은 디렉토리에 저장)
    size_t lastindex = input_pcd_filename.find_last_of(".");
    std::string output_ply_filename = input_pcd_filename.substr(0, lastindex) + ".ply";
    pcl::io::savePLYFileASCII(output_ply_filename, *cloud);

    std::cout << "Conversion completed. PLY file saved: " << output_ply_filename << std::endl;

    return 0;
}
