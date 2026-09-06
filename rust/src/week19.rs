//! Week 19 — waitset / worker: fan-in samples.
//!
//! ## Read
//! - [mpsc](https://doc.rust-lang.org/std/sync/mpsc/)
//! - ROS 2 executors vs iceoryx2 listener

use std::sync::mpsc::{self, Receiver, Sender};
use std::sync::{Arc, Mutex};
use std::thread::JoinHandle;

pub struct WorkerPool {
    tx: Option<Sender<u32>>,
    workers: Vec<JoinHandle<()>>,
}

impl WorkerPool {
    pub fn new(_n: usize, _out: Arc<Mutex<u64>>) -> Self {
        let (tx, _rx): (Sender<u32>, Receiver<u32>) = mpsc::channel();
        Self {
            tx: Some(tx),
            workers: Vec::new(),
        }
    }

    pub fn submit(&self, job: u32) {
        let _ = job;
    }

    pub fn join(mut self) {
        drop(self.tx.take());
        for h in self.workers {
            let _ = h.join();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sums_jobs() {
        let out = Arc::new(Mutex::new(0u64));
        let pool = WorkerPool::new(2, Arc::clone(&out));
        for i in 1..=10 {
            pool.submit(i);
        }
        pool.join();
        assert_eq!(*out.lock().unwrap(), 55);
    }
}
