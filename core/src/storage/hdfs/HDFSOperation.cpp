#include "HDFSOperation.h"
#include "HDFSClient.h"

namespace milvus {
namespace storage {

HDFSOperation::HDFSOperation(const std::string& dir_path_) : dir_path_(dir_path_) {
    HDFSClient::getInstance();
}

void
HDFSOperation::CreateDirectory() {
    HDFSClient::getInstance().CreateDirectory(const_cast<char*>(dir_path_.c_str()));
}

const std::string&
HDFSOperation::GetDirectory() {
    return dir_path_;
}

void
HDFSOperation::ListDirectory(std::vector<std::string>& file_paths) {
    HDFSClient::getInstance().ListDirectory(file_paths, dir_path_);
}

bool
HDFSOperation::DeleteFile(const std::string& file_path) {
    return HDFSClient::getInstance().DeleteFile(file_path);
}

}  // namespace storage
}  // namespace milvus