import pandas as pd
import os

CSV_FILE = "reports/csv/benchmark.csv"

if not os.path.exists(CSV_FILE):
    raise FileNotFoundError(
        f"{CSV_FILE} not found"
    )

df = pd.read_csv(CSV_FILE)

if df.empty:
    raise ValueError(
        "Benchmark file is empty"
    )

if (df["time"] < 0).any():
    raise ValueError(
        "Negative execution times detected"
    )

print(
    "Benchmark validation passed"
)