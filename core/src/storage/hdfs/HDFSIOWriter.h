
#pragma once

#include <memory>
#include <string>
#include "hdfs.h"
#include "storage/IOWriter.h"

namespace milvus {
namespace storage {

class HDFSIOWriter : public IOWriter {
 public:
    HDFSIOWriter() = default;
    ~HDFSIOWriter() = default;

    HDFSIOWriter(const HDFSIOWriter&) = delete;
    HDFSIOWriter(HDFSIOWriter&&) = delete;

    HDFSIOWriter&
    operator=(const HDFSIOWriter&) = delete;
    HDFSIOWriter&
    operator=(HDFSIOWriter&&) = delete;

    bool
    open(const std::string& name) override;

    void
    write(void* ptr, int64_t size) override;

    int64_t
    length() override;

    void
    close() override;

 public:
    int64_t len_;
    std::string name_;
};
using HDFSIOWriterPtr = std::shared_ptr<HDFSIOWriter>;
}  // namespace storage
}  // namespace milvus