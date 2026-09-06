//! Week 17 — `dyn Subscription` (runtime poly on a node).
//!
//! Same problem as C++ week 10: mixed topics on one node.
//! iceoryx2 would rather give you two typed subscribers.
//!
//! ## Read
//! - [Trait objects](https://doc.rust-lang.org/book/ch17-02-trait-objects.html)

pub trait Subscription {
    fn topic(&self) -> &str;
    fn on_bytes(&mut self, bytes: &str);
}

pub struct CountingSub {
    topic: String,
    pub hits: u32,
}

impl CountingSub {
    pub fn new(topic: impl Into<String>) -> Self {
        Self {
            topic: topic.into(),
            hits: 0,
        }
    }
}

impl Subscription for CountingSub {
    fn topic(&self) -> &str {
        &self.topic
    }
    fn on_bytes(&mut self, _bytes: &str) {
        self.hits += 1;
    }
}

pub struct Node {
    subs: Vec<Box<dyn Subscription>>,
}

impl Node {
    pub fn new() -> Self {
        Self { subs: Vec::new() }
    }

    pub fn add(&mut self, sub: Box<dyn Subscription>) {
        let _ = sub;
    }

    pub fn inject(&mut self, topic: &str, bytes: &str) {
        let _ = (topic, bytes);
    }

    pub fn sub_hits(&self, topic: &str) -> Option<u32> {
        let _ = topic;
        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn match_topic() {
        let mut n = Node::new();
        n.add(Box::new(CountingSub::new("/scan")));
        n.add(Box::new(CountingSub::new("/imu")));
        n.inject("/scan", "d");
        assert_eq!(n.sub_hits("/scan"), Some(1));
        assert_eq!(n.sub_hits("/imu"), Some(0));
    }
}
