#include <memory>
#include <string>
#include "HDFSClient.h"
#include "storage/IOReader.h"
#include "storage/hdfs/hdfs.h"

namespace milvus {
namespace storage {

class HDFSIOReader : public IOReader {
 public:
    HDFSIOReader() = default;
    ~HDFSIOReader() = default;
    HDFSIOReader(const HDFSIOReader&) = delete;
    HDFSIOReader(HDFSIOReader&&) = delete;

    HDFSIOReader&
    operator=(const HDFSIOReader&) = delete;
    HDFSIOReader&
    operator=(HDFSIOReader&&) = delete;

    bool
    open(const std::string& name) override;

    // read data from hdfs to the pointed buffer
    void
    read(void* ptr, int64_t size) override;

    void seekg(int64_t) override;

    int64_t
    length() override;

    void
    close() override;

 public:
    std::string name_;
};

using HDFSIOReaderPtr = std::shared_ptr<HDFSIOReader>;

}  // namespace storage
}  // namespace milvus
