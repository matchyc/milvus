#include "storage/hdfs/HDFSIOReader.h"
#include "HDFSClient.h"

namespace milvus {
namespace storage {

bool
HDFSIOReader::open(const std::string& name) {
    name_ = name;
    return HDFSClient::getInstance().read_open(name.c_str());
}

void
HDFSIOReader::read(void* ptr, int64_t size) {
    HDFSClient::getInstance().read(reinterpret_cast<char*>(ptr), size);
}

void
HDFSIOReader::seekg(int64_t pos) {
    HDFSClient::getInstance().seekg(pos);
}

int64_t
HDFSIOReader::length() {
    return HDFSClient::getInstance().length(name_);
}

void
HDFSIOReader::close() {
    HDFSClient::getInstance().close();
}

}  // namespace storage

}  // namespace milvus
