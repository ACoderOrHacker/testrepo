/**
 * @file scope_exit.ixx
 * @brief `scope_exit` supports for OE.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
export module oe.scope_guard.scope_exit;

import oe.meta;
import oe.functional.invoke;

export namespace oe {
/**
 * @brief Scope guard `scope_exit`.
 * @details Manage the cleanup after the scope exits. Just like Go's defer or
 * D's scope. You can automatically use a given cleanup function at the end of a
 * scope (even if an exception occurs), and you can control whether the cleanup
 * is executed yourself.
 * If you `release` the guard, you cannot `restore` it as an active state.
 * @warning `scope_exit` should never be allocated in heap memories. You should
 * always create it at the stack. If it's allocated in heap and the passing
 * function is a lambda with references to the local object. The cleanup
 * function will get a dangling reference.
 *
 * For example, if `scope_exit` has the `operator new`:
 * @code{.cpp}
 * import oe.scope_guard.scope_exit;
 *
 * auto foo() {
 *      int i = 1;
 *      auto cleanup = new oe::scope_exit([&]() { i = 2; });
 *
 *      // `cleanup` is *not* destroyed, the cleanup function will not be called
 *      // at here.
 *
 *      return cleanup;
 * }
 *
 * int main() {
 *      auto p = foo(); // Get the cleaner.
 *      delete p; // UB! Get a dangling reference of `i` in lambda.
 *      return 0;
 * }
 * @endcode
 *
 * @tparam F The cleanup function type.
 */
template <typename F> class scope_exit {
  public:
    static_assert(oe::is_invocable_r_v<void, F>,
                  "Cleanup functions should be noexcept and be the same type "
                  "of void()");

    explicit inline scope_exit(F&& fn) noexcept : m_fn{fn}, m_is_active{true} {}

    inline scope_exit(scope_exit&& other) noexcept
        : m_fn{other.m_fn}, m_is_active{other.m_is_active} {
        other.m_is_active = false; // Avoid the double-clean.
    }

    inline ~scope_exit() noexcept {
        if (m_is_active)
            invoke(m_fn);
    }

    // Deleted because const& constructor copies a function, the cleanup
    // function will be called multiply.
    scope_exit(const scope_exit&) = delete;

    /**
     * @brief Release the scope guard so that the cleanup function will not be
     * called.
     */
    void release() noexcept { m_is_active = false; }

  private:
    F m_fn;           //!< The cleanup function that runs on the scope exits.
    bool m_is_active; //!< The activation flag that decides whether to
                      //!< run the cleanup function `m_fn`
};
} // namespace oe