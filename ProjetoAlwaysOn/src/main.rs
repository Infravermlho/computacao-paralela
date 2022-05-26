use rayon::prelude::*;
use std::time::Instant;

//const N: u64 = 18446744073709551615;
const CHUNKDIV: u64 = 100000;
const INCREMENT: u64 = 5000000000;

fn div(k: u64) -> f64 {
    let mut num = 0.0;
    for y in k..k + CHUNKDIV {
        num += 1.0 / (y) as f64;
    }
    num
}

pub fn taylor_with_rayon() -> f64 {
  let totaltime = Instant::now();
  let mut last_update = Instant::now();

  let mut sum: f64 = 0.0;
  let mut bucket: f64;
  let mut iteration: u64 = 0;
  
  loop {
    bucket = (0..(INCREMENT/CHUNKDIV)).collect::<Vec<_>>().par_iter().map(|&i| div(((i * CHUNKDIV) + 1) + (INCREMENT * iteration))).sum();
    sum += bucket; 
      
    println!("N atual = {:?} com o resultado de = {:?}", INCREMENT * (iteration + 1), sum);
    let ndone = Instant::now();
    println!("Tempo total elapsado = {:?} tempo des da ultima atualização = {:?}", ndone.duration_since(totaltime),   ndone.duration_since(last_update));
    last_update = Instant::now();

    println!("");

    iteration += 1;
  }
}

fn main() {
  taylor_with_rayon();
}
