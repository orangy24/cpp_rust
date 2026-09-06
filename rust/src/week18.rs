//! Week 18 — FFI to the week-11 C node (rmw-shaped).
//!
//! C is already in `pipeline.c` (symbols `node_*`). Wrap it safely.
//!
//! ## Read
//! - [Nomicon FFI](https://doc.rust-lang.org/nomicon/ffi.html)

use std::os::raw::c_char;

#[repr(C)]
pub struct NodeHandle {
    _private: [u8; 0],
}

extern "C" {
    pub fn node_new() -> *mut NodeHandle;
    pub fn node_free(n: *mut NodeHandle);
    pub fn node_publish(n: *mut NodeHandle, bytes: *const c_char);
    pub fn node_count(n: *const NodeHandle) -> i32;
}

pub struct SafeNode {
    #[allow(dead_code)]
    raw: *mut NodeHandle,
}

impl SafeNode {
    pub fn new() -> Option<Self> {
        None
    }

    pub fn publish(&mut self, bytes: &str) {
        let _ = bytes;
    }

    pub fn count(&self) -> i32 {
        0
    }
}

impl Drop for SafeNode {
    fn drop(&mut self) {}
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn counts() {
        let mut n = SafeNode::new().expect("node_new");
        n.publish("a");
        n.publish("b");
        assert_eq!(n.count(), 2);
    }
}
