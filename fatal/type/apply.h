/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef FATAL_INCLUDE_fatal_type_apply_h
#define FATAL_INCLUDE_fatal_type_apply_h

#include <fatal/type/impl/apply.h>

namespace fatal {

template <typename T>
using apply_to = impl_apply::to<T>;

template <template <typename...> class T>
struct applier {
  template <typename... Args>
  using apply = typename impl_apply::applier<T, Args...>::type;
};

template <typename T, typename... Bound>
struct curry {
  template <typename... Args>
  using apply = typename impl_apply::applier<
    T::template apply, Bound..., Args...
  >::type;
};

template <typename T, typename... Bound>
struct curry_back {
  template <typename... Args>
  using apply = typename impl_apply::applier<
    T::template apply, Args..., Bound...
  >::type;
};

} // namespace fatal {

#include <fatal/type/deprecated/apply.h>

#endif // FATAL_INCLUDE_fatal_type_apply_h
