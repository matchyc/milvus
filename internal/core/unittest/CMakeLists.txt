# Copyright (C) 2019-2020 Zilliz. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software distributed under the License
# is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
# or implied. See the License for the specific language governing permissions and limitations under the License

include_directories(${CMAKE_HOME_DIRECTORY}/src)
include_directories(${CMAKE_HOME_DIRECTORY}/src/thirdparty)

add_definitions(-DMILVUS_TEST_SEGCORE_YAML_PATH="${CMAKE_SOURCE_DIR}/unittest/test_utils/test_segcore.yaml")

# TODO: better to use ls/find pattern
set(MILVUS_TEST_FILES
        init_gtest.cpp
        test_bf.cpp
        test_binary.cpp
        test_bitmap.cpp
        test_bool_index.cpp
        test_common.cpp
        test_concurrent_vector.cpp
        test_conf_adapter_mgr.cpp
        test_c_api.cpp
        test_expr.cpp
        test_growing.cpp
        test_indexing.cpp
        test_index_c_api.cpp
        test_index_wrapper.cpp
        test_init.cpp
        test_parquet_c.cpp
        test_plan_proto.cpp
        test_query.cpp
        test_reduce.cpp
        test_reduce_c.cpp
        test_relational.cpp
        test_retrieve.cpp
        test_scalar_index.cpp
        test_sealed.cpp
        test_segcore.cpp
        test_similarity_corelation.cpp
        test_span.cpp
        test_string_expr.cpp
        test_timestamp_index.cpp
        test_utils.cpp
        )

if (LINUX OR APPLE)
    set(MILVUS_TEST_FILES
            ${MILVUS_TEST_FILES}
            test_scalar_index_creator.cpp
            test_string_index.cpp
            )
endif()

if (LINUX)
    # check if memory leak exists in index builder
    set(INDEX_BUILDER_TEST_FILES
            test_index_wrapper.cpp
            test_scalar_index_creator.cpp
            test_index_c_api.cpp
            )

    add_executable(index_builder_test
            ${INDEX_BUILDER_TEST_FILES}
            )

    target_link_libraries(index_builder_test
            gtest
            gtest_main
            milvus_segcore
            milvus_indexbuilder
            milvus_index
            milvus_log
            pthread
            )
    install(TARGETS index_builder_test DESTINATION unittest)
endif()

add_executable(all_tests
        ${MILVUS_TEST_FILES}
        )

target_link_libraries(all_tests
        gtest
        milvus_segcore
        milvus_indexbuilder
        milvus_index
        milvus_log
        milvus_storage
        pthread
        )

install(TARGETS all_tests DESTINATION unittest)

if (LINUX)
    add_subdirectory(bench)
endif ()
