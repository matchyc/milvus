
#pragma once

#include "hdfs.h"
#include "storage/Operation.h"

#include <memory>
#include <string>
#include <vector>

namespace milvus {
namespace storage {

class HDFSOperation : public Operation {
 public:
    // constructor
    explicit HDFSOperation(const std::string& dir_path);

    void
    CreateDirectory();

    const std::string&
    GetDirectory();

    void
    ListDirectory(std::vector<std::string>& file_paths);

    bool
    DeleteFile(const std::string& file_path);

 public:
    const std::string dir_path_;
};
using HDFSOperationPtr = std::shared_ptr<HDFSOperation>;
}  // namespace storage
}  // namespace milvus