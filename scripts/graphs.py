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

# Guardar gráfica
plt.savefig(
    "reports/png/benchmark.png"
)

print(
    "Graph saved to reports/png/benchmark.png"
)