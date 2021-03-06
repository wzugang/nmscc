#pragma once

#include <nms/cuda/base.h>
#include <nms/cuda/runtime.h>

struct _nvrtcProgram;

namespace nms::cuda
{

struct Vrun;

/*! cuda program */
class Program
{
    friend class  Module;
    friend struct Vrun;

public:
    /**
     * constructor
     * @param source: cuda source (*.cu)
     */
    Program(StrView src): Program() {
        src_.appends(src);
    }

    Program()
        : src_(4*1024*1024)
        , ptx_(4*1024*1024)
    { }

    ~Program()
    { }

    /*! complile cuda source to ptx */
    NMS_API bool compile();

    /*! get cuda src */
    auto& src() {
        return src_;
    }

    /*! get cuda src */
    auto& src() const {
        return src_;
    }

    /*! get cuda ptx */
    auto& ptx() const {
        return ptx_;
    }

protected:
    U8String<0>  src_;
    U8String<0>  ptx_;
};

}

