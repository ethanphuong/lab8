#ifndef __CONTAINER_CPP
#define __CONTAINER_CPP

#include "container.hpp"
#include "base.hpp"

void Container::set_sort_function(Sort* sort_function){
     this->sort_function = sort_function;
}


#endif
