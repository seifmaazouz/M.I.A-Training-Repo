import pandas as pd
import matplotlib.pyplot as plt

# 1) Load the dataset as a dataframe:
df = pd.read_csv("Weather Dataset.csv")


# 2) Clean and preprocess the data:
# handle missing values
df = df.dropna()

# remove duplicates 
df = df.drop_duplicates()

# handle incorrect data
df = df[(-90 < df['Temperature (C)']) & (df['Temperature (C)'] < 60)] # checks if temperature is withen acceptable range
df = df[(-90 < df['Apparent Temperature (C)']) & (df['Apparent Temperature (C)'] < 60)] # checks if temperature is withen acceptable range
df = df[(df['Humidity'] >= 0) & (df['Humidity'] <= 1)] # checks to see if humidity is from 0 to 1 range
df = df[(df['Wind Speed (km/h)'] >= 0) & (df['Wind Bearing (degrees)'] >= 0) & (df['Visibility (km)'] >= 0)] # checks to see if values are positive



# 3) Plot temperature over time.
df = df.sort_values(by='Formatted Date', ascending=True) # sort date in ascending order

# plot graph
plt.figure(figsize=(10, 5))
plt.plot(df['Formatted Date'], df['Temperature (C)'])
plt.title('Temperature Over Time')
plt.xlabel('Time')
plt.ylabel('Temperature (C)')
plt.grid(True)
plt.xticks(df['Formatted Date'][::200], rotation='vertical')
plt.tight_layout()
plt.show()


# 4) Create a histogram of temperature distribution.
plt.hist(df['Temperature (C)'])
plt.xlabel('Temperature')
plt.ylabel('Frequency')
plt.title('Histogram of Temperature Distribution')
plt.show()


# 4) Plot a scatter plot of temperature vs. humidity.
plt.scatter(df['Temperature (C)'], df['Humidity'], alpha=0.5)
plt.xlabel('Temperature')
plt.ylabel('Humidity')
plt.title('Scatter Plot of Temperature vs. Humidity')
plt.show()


# 5)

import seaborn as sb

df_numeric = df.select_dtypes(include=['number'])

# Compute the correlation matrix
corr = df_numeric.corr()

sb.heatmap(corr, annot=True, cmap='coolwarm', vmin=-1, vmax=1)
plt.title('Correlation Heatmap')
plt.show()

# df.to_csv("cleaned dataset.csv", index=False)
