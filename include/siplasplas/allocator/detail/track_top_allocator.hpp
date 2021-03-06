#ifndef SIPLASPLAS_ALLOCATOR_DETAIL_TRACK_TOP_ALLOCATOR_HPP
#define SIPLASPLAS_ALLOCATOR_DETAIL_TRACK_TOP_ALLOCATOR_HPP

#include "embedded_allocator.hpp"
#include <siplasplas/allocator/export.hpp>

#include <sstream>

namespace cpp
{
    class SIPLASPLAS_ALLOCATOR_EXPORT TrackTopAllocator : protected EmbeddedAllocator
    {
    protected:
        TrackTopAllocator(void* begin, void* end);

        char* top() const;
        void set_top(void* pointer);

        void commit(std::size_t bytes);
        void decommit(std::size_t bytes);

        std::size_t bytes() const;
        std::size_t bytes_left() const;
        bool belongs_to_storage(void* pointer) const;
        bool full() const;

        std::string dump() const;
    };
}

#endif // SIPLASPLAS_ALLOCATOR_TRACK_TOP_ALLOCATOR_HPP
