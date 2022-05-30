1 - Instalar rust: https://rustup.rs/

2 - Colocar os arquivos em uma pasta, mantendo a mesma estrutura

3 - No terminal navegar até a pasta e executar ``cargo build --release``

4 - E depois ``cargo run --release`` (não colocar o release vai impactar drasticamente a performance)

### Resultados esperados

O programa vai calcular a série de Taylor infinitamente em incrementos de ln(5000000000) usando Rayon para paralelização de data
