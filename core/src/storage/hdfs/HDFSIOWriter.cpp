
#include "HDFSIOWriter.h"
#include "HDFSClient.h"
namespace milvus {
namespace storage {

bool
HDFSIOWriter::open(const std::string& name) {
    name_ = name;
    len_ = 0;
    return HDFSClient::getInstance().write_open(name.c_str());
}

void
HDFSIOWriter::write(void* ptr, int64_t size) {
    HDFSClient::getInstance().write(reinterpret_cast<char*>(ptr), size);
    len_ += size;
}

int64_t
HDFSIOWriter::length() {
    return len_;
}

void
HDFSIOWriter::close() {
    HDFSClient::getInstance().close();
}

}  // namespace storage
}  // namespace milvus