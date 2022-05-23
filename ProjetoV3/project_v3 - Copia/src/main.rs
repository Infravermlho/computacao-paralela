use num::clamp;
//use num::{BigUint, One};
use rayon::prelude::*;
use std::time::Instant;
//use simdeez::*;

const N: u64 = 1000000;
const INCREMENT: u64 = 1000000000;

fn div(k: u64) -> f64 {
    let num = 1.0 / (k) as f64;
    //println!("num is {:.32}", k);
    //println!("num is {:.32}", num);
    num
}

pub fn taylor_with_rayon(n: u64) -> f64 {
    let mut sum: f64 = 0.0;
    let mut cursor: u64 = 1;

    while cursor < n {
        let cursorend = clamp(cursor+INCREMENT, 1, n + 1);
        let bucket: f64 = (cursor..cursorend).collect::<Vec<_>>().par_iter().map(|&i| div(i)).sum();
        sum += bucket;

        cursor += INCREMENT;
        if cursor > n {cursor = n}
    }
    sum
}

pub fn taylor_iterative(n: u64) -> f64 {
    //(1..n+1).collect::<Vec<_>>().iter().map(|&i| div(i)).sum()
    let mut sum: f64 = 0.0;
    let mut cursor: u64 = 1;

    while cursor < n {
        let cursorend = clamp(cursor+INCREMENT, 1, n + 1);
        let bucket: f64 = (cursor..cursorend).collect::<Vec<_>>().iter().map(|&i| div(i)).sum();
        sum += bucket;

        cursor += INCREMENT;
        if cursor > n {cursor = n}
        println!("{}", cursor)
    }
    sum
}

// pub fn taylor_simd(n: u64) -> f64 { //SINGLE INSTRUCTION. MULTIPLE DATA.
    
// }

fn main() {
    let now = Instant::now();
    println!("Taylor Iterativo = {}", taylor_iterative(N));
    let new_now = Instant::now();
    println!("runtime = {:?}", new_now.duration_since(now));

    let now = Instant::now();
    println!("Taylor com Rayon = {}", taylor_with_rayon(N));
    let new_now = Instant::now();
    println!("runtime = {:?}", new_now.duration_since(now));
}