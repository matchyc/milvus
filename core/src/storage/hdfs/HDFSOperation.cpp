//License...?

#include <boost/filesystem.hpp>

// #include <fiu-local.h>

#include "utils/Exception.h"
#include "utils/Log.h"

#include "HDFSOperation.h"



namespace milvus{
namespace storage{

HDFSOperation::HDFSOperation(const std::string& dir_path_):dir_path_(dir_path_){
        hdfs_fs = hdfsConnect("default", 0);
}

void
HDFSOperation::CreateDirectory() {
        //dont't check the dir_path_ for now
        //don't use fiu_do_on for now
        int flag = hdfsCreateDirectory(hdfs_fs, dir_path_.c_str());
        if(flag == -1){
            //error do something like
            //std::string err_msg = "Failed to create directory: " + dir_path_;
            //LOG_ENGINE_ERROR_ << err_msg;
            //throw Exception(SERVER_CANNOT_CREATE_FOLDER, err_msg);
        }
}

const std::string&
HDFSOperation::GetDirectory() {
        return dir_path_;
}

void
HDFSOperation::ListDirectory(std::vector<std::string>& file_paths) {
        int numEntries = 0;
        hdfsFileInfo* file_list = nullptr;
        if((file_list = hdfsListDirectory(hdfs_fs, dir_path_.c_str(), &numEntries)) != nullptr) {
                for(int i = 0; i < numEntries; ++i) {
                    std::string temp(dir_path_);
                    temp.append(file_list[i].mName);
                    file_paths.emplace_back(temp);
                }
                hdfsFreeFileInfo(file_list, numEntries);
        }
        else{
                //error or empty directory
        }
}

bool
HDFSOperation::DeleteFile(const std::string& file_path) {
        int flag = hdfsDelete(hdfs_fs, file_path.c_str(), 0);

        if(flag == 0)
            return true;
        else
            return false;
}


}
}