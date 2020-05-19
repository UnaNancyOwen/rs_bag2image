#ifndef __REALSENSE__
#define __REALSENSE__

#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>

#include <array>

#if __has_include(<filesystem>)
#include <filesystem>
namespace filesystem = std::filesystem;
#else
#include <experimental/filesystem>
#if _WIN32
namespace filesystem = std::experimental::filesystem::v1;
#else
namespace filesystem = std::experimental::filesystem;
#endif
#endif

class RealSense
{
private:
    // RealSense
    rs2::pipeline pipeline;
    rs2::pipeline_profile pipeline_profile;
    rs2::frameset frameset;

    // Color Buffer
    rs2::frame color_frame;
    cv::Mat color_mat;
    uint32_t color_width;
    uint32_t color_height;

    // Depth Buffer
    rs2::frame depth_frame;
    cv::Mat depth_mat;
    uint32_t depth_width;
    uint32_t depth_height;

    // Infrared Buffer
    std::array<rs2::frame, 2> infrared_frames;
    std::array<cv::Mat, 2> infrared_mats;
    uint32_t infrared_width;
    uint32_t infrared_height;

    filesystem::path bag_file;
    filesystem::path directory;
    std::vector<int32_t> params;
    bool scaling = false;
    bool display = false;

public:
    // Constructor
    RealSense( int argc, char* argv[] );

    // Destructor
    ~RealSense();

    // Processing
    void run();

private:
    // Initialize
    void initialize( int argc, char * argv[] );

    // Initialize Parameter
    inline void initializeParameter( int argc, char* argv[] );

    // Initialize Sensor
    inline void initializeSensor();

    // Initialize Save
    inline void initializeSave();

    // Finalize
    void finalize();

    // Update Data
    void update();

    // Update Frame
    inline void updateFrame();

    // Update Color
    inline void updateColor();

    // Update Depth
    inline void updateDepth();

    // Update Infrared
    inline void updateInfrared();

    // Draw Data
    void draw();

    // Draw Color
    inline void drawColor();

    // Draw Depth
    inline void drawDepth();

    // Draw Infrared
    inline void drawInfrared();

    // Show Data
    void show();

    // Show Color
    inline void showColor();

    // Show Depth
    inline void showDepth();

    // Show Infrared
    inline void showInfrared();

    // Save Data
    void save();

    // Save Color
    inline void saveColor();

    // Save Depth
    inline void saveDepth();

    // Save Infrared
    inline void saveInfrared();
};

#endif // __REALSENSE__