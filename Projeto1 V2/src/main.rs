use std::time::Instant;
use rayon::prelude::*;

fn div(k: u32) -> f64 {
  let num = 1.0 / (k) as f64;
  //println!("num is {:.32}", k);
  //println!("num is {:.32}", num);
  num
}

pub fn taylor_with_rayon(n: u32) -> f64 {
  (1..n+1).collect::<Vec<_>>().par_iter().map(|&i| div(i)).sum()
}

fn main() {
  let now = Instant::now();
  println!("Taylor com Rayon = {}", taylor_with_rayon(100000000));

  let new_now = Instant::now();
  println!("runtime = {:?}", new_now.duration_since(now));
}