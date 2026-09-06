//! Week 15 — loaned sample ownership (iceoryx2-style).
//!
//! ## Read
//! - [The Book ch. 4](https://doc.rust-lang.org/book/ch04-00-understanding-ownership.html)
//! - [iceoryx2](https://iceoryx2.io/) loaned samples
//! - [ROS 2 loaned messages](https://docs.ros.org/en/rolling/How-To-Guides/Using-loaned-messages.html)

pub struct SamplePool {
    in_use: bool,
    slot: String,
    last: Option<String>,
}

pub struct SampleLoan<'a> {
    pool: Option<&'a mut SamplePool>,
}

impl SamplePool {
    pub fn new() -> Self {
        Self {
            in_use: false,
            slot: String::new(),
            last: None,
        }
    }

    pub fn last_published(&self) -> Option<&str> {
        self.last.as_deref()
    }

    pub fn loan(&mut self) -> Option<SampleLoan<'_>> {
        let _ = self;
        None
    }
}

impl SampleLoan<'_> {
    pub fn payload_mut(&mut self) -> &mut String {
        unimplemented!("TODO")
    }

    pub fn publish(self) {
        let _ = self;
    }
}

impl Drop for SampleLoan<'_> {
    fn drop(&mut self) {
        // TODO: if still holding pool, clear in_use
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn publish_sets_last() {
        let mut pool = SamplePool::new();
        {
            let mut loan = pool.loan().expect("loan");
            loan.payload_mut().push_str("scan");
            loan.publish();
        }
        assert_eq!(pool.last_published(), Some("scan"));
    }
}
