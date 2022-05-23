use simdeez::*;
use simdeez::scalar::*;
use simdeez::sse2::*;
use simdeez::sse41::*;
use simdeez::avx2::*;

use std::time::Instant;

const N: u64 = 1000000;

// ele usa essa macro para detectar qual metodo de SIMD é o mais efetivo
simd_runtime_generate!(
fn taylor(n: &[f64], div: &[f64]) -> Vec<f64>{

    let mut result: Vec<f64> = Vec::with_capacity(n.len());
    result.set_len(n.len());
        
    let mut n   = &n[..n.len()];
    let mut div = &div[..n.len()];
    let mut res = &mut result[..n.len()];

    while n.len() >= S::VF64_WIDTH {
        //Carregar data do VEC para um valor SIMD
        let nv   = S::loadu_pd(&n[0]);
        let divv = S::loadu_pd(&div[0]);
 
        let divresult = nv / divv;

        S::storeu_pd(&mut res[0], divresult);
             
        // Mover cada parte para a nova posição
        n   = &n[S::VF64_WIDTH..];
        div = &div[S::VF64_WIDTH..];
        res = &mut res[S::VF64_WIDTH..];
    }
    
    //cuida das sobras (certos metodos de SIMD vão de 4 em 4, 8 em 8 e etc)
    for i in 0..n.len() {
        let divresult = n[i] / div[i];
        res[i] = divresult;
    }

    result
});

fn main() {
    let now = Instant::now();
    let n_vec: Vec<f64> = vec![1.0; (N).try_into().unwrap()];
    let div_vec: Vec<f64> = (1..N + 1).map(|x|x as f64).collect();

    let result: Vec<f64> = taylor_runtime_select(&n_vec, &div_vec);
    let sum: f64 = result.iter().sum();

    let new_now = Instant::now();
    println!("{}", sum);
    println!("runtime = {:?}", new_now.duration_since(now));
}