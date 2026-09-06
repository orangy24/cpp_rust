//! Week 16 — `Message` trait (static polymorphism).
//!
//! ## Read
//! - [The Book ch. 10](https://doc.rust-lang.org/book/ch10-00-generics.html)
//! - ROS 2 `Publisher<T>` / iceoryx2 typed payload

pub trait Message {
    const TYPE_NAME: &'static str;
    fn payload(&self) -> &str;
}

pub fn topic_type<T: Message>(msg: &T) -> &'static str {
    let _ = msg;
    ""
}

pub struct LaserScan {
    pub bytes: String,
}

impl Message for LaserScan {
    const TYPE_NAME: &'static str = "sensor_msgs/LaserScan";
    fn payload(&self) -> &str {
        &self.bytes
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn type_name() {
        let m = LaserScan {
            bytes: "range".into(),
        };
        assert_eq!(topic_type(&m), "sensor_msgs/LaserScan");
    }
}
