import pandas as pd
import matplotlib.pyplot as plt

# Leer resultados del benchmark
df = pd.read_csv(
    "reports/csv/benchmark.csv"
)

# Crear gráfica
plt.figure(figsize=(8, 5))

plt.plot(
    df["size"],
    df["time"],
    marker="o"
)

plt.xlabel("Input Size")
plt.ylabel("Execution Time (s)")
plt.title("Benchmark Results")

plt.grid(True)

# Guardar gráfica en png
plt.savefig(
    "reports/png/benchmark.png"
)

# Guardar gráfica en png
plt.savefig(
    "reports/pdf/benchmark.pdf"
)

print(
    "Graphs saved"
)