import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("../results/simulation.csv")

vaccination_days = df[df["vaccinated"].diff() > 0]

fig, ax = plt.subplots(figsize=(10, 6))

ax.set_facecolor("#ededed")
ax.grid(True, color="white")
ax.set_axisbelow(True)

ax.plot(df["day"], df["susceptible"], label="Susceptible")
ax.plot(df["day"], df["infected"], label="Infected")
ax.plot(df["day"], df["recovered"], label="Recovered")
ax.plot(df["day"], df["deceased"], label="Deceased")

ax.set_xlabel("Simulation Day")
ax.set_ylabel("Population")
ax.set_title("Epidemic Simulation with Population Cumulative Vaccination Coverage")

ax.legend(title="Health Status")

population = (
    df["susceptible"]
    + df["infected"]
    + df["recovered"]
    + df["deceased"]
).iloc[0]

vaccination_days = df[df["vaccinated"].diff() > 0]

for _, row in vaccination_days.iterrows():
    proportion = row["vaccinated"] / population * 100

    ax.axvline(
        x=row["day"],
        linestyle="--",
        alpha=0.6,
        color='purple'
    )
   
    ax.text(
        row["day"],
        -0.04,
        f"{proportion:.1f}%",
        transform=ax.get_xaxis_transform(),
        rotation=90,
        ha="center",
        va="top"
    )

ax.spines["top"].set_visible(False)
ax.spines["right"].set_visible(False)
plt.tight_layout()
plt.savefig('epidemic_visualisation.png', dpi=300)