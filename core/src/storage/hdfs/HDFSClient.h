#pragma once

#include "hdfs.h"
#include "utils/Status.h"
//now the addr is a default one
//todo: make everyone can connect to their own cluster
const char* namdenode_addr = "hdfs://localhost:9000";

namespace milvus{
namespace storage{

//try to use singleton in 9/9/2020
class HDFSClient{
public:
        static HDFSClient& 
        getInstance(){
                static HDFSClient instance;
                return instance;
        }

        ~HDFSClient() = default;
        HDFSClient(const HDFSClient&)  = delete;
        HDFSClient(HDFSClient&&) = delete;
        HDFSClient& 
        operator = (const HDFSClient&) = delete;
        HDFSClient&
        operator = (HDFSClient&&) = delete;

        Status
        open(const char* name);

        void
        read(char* ptr, int64_t size);

        void
        seekg(int64_t pos);

        int64_t
        length(std::string name);

        void
        close();
private:
        HDFSClient() ;
        struct hdfsBuilder * bld_;
         hdfsFS hdfs_fs_;
         hdfsFile hdfs_file_;
};

}
}