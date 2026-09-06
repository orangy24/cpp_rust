//! Week 20 — pick the poly: ROS 2 vs iceoryx2.
//!
//! Write `choose_api` documenting the trade (not a real middleware).
//!
//! ## Read
//! - [ROS 2 topics](https://docs.ros.org/en/rolling/Concepts/Basic/About-Topics.html)
//! - [iceoryx2](https://iceoryx2.io/)
//! - [Rust API guidelines](https://rust-lang.github.io/api-guidelines/)

#[derive(Debug, PartialEq, Eq)]
pub enum Stack {
    /// DDS/rmw, many QoS knobs, multi-language via C.
    Ros2,
    /// Shared-memory first, typed ports, fewer QoS knobs.
    Iceoryx2,
}

/// If `zero_copy_hot_path` is true and `multi_language` is false → Iceoryx2.
/// If `multi_language` is true → Ros2.
/// If both false → Iceoryx2 (simpler IPC).
/// If both true → Ros2 (need rmw).
pub fn choose_api(zero_copy_hot_path: bool, multi_language: bool) -> Stack {
    let _ = (zero_copy_hot_path, multi_language);
    Stack::Ros2
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn rmw_when_languages() {
        assert_eq!(choose_api(true, true), Stack::Ros2);
        assert_eq!(choose_api(false, true), Stack::Ros2);
    }

    #[test]
    fn iceoryx_when_shm_same_lang() {
        assert_eq!(choose_api(true, false), Stack::Iceoryx2);
        assert_eq!(choose_api(false, false), Stack::Iceoryx2);
    }
}
