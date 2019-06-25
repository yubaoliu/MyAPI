import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Loading the data

# Reading the csv file into a pandas DataFrame
data = pd.read_csv('student_data.csv')

# Printing out the first 10 rows of our data
print(data[:10])

# Plotting the data
def plot_points(data):
    X = np.array(data[["gre", "gpa"]])
    y = np.array(data["admit"])
    admitted = X[np.argwhere(y == 1)]
    rejected = X[np.argwhere(y == 0)]
    plt.scatter([s[0][0] for s in rejected], [s[0][1] for s in rejected], s=25, color='red', edgecolor='k')
    plt.scatter([s[0][0] for s in admitted], [s[0][1] for s in admitted], s=25, color='cyan', edgecolor='k')
    plt.xlabel('Test (GRE)')
    plt.ylabel('Grades (GPA)')


plot_points(data)
plt.show()


# Separating the ranks
data_rank1 = data[data["rank"]==1]
data_rank2 = data[data["rank"]==2]
data_rank3 = data[data["rank"]==3]
data_rank4 = data[data["rank"]==4]

# Plotting the graphs
plot_points(data_rank1)
plt.title("Rank 1")
plt.show()
plot_points(data_rank2)
plt.title("Rank 2")
plt.show()
plot_points(data_rank3)
plt.title("Rank 3")
plt.show()
plot_points(data_rank4)
plt.title("Rank 4")
plt.show()


## One solution
# Make dummy variables for rank
#one_hot_data = pd.concat([data, pd.get_dummies(data['rank'], prefix='rank')], axis=1)

# Drop the previous rank column
#one_hot_data = one_hot_data.drop('rank', axis=1)

# Print the first 10 rows of our data
#one_hot_data[:10]


## Alternative solution ##
# if you're using an up-to-date version of pandas,
# you can also use selection by columns

# an equally valid solution

one_hot_data = pd.get_dummies(data, columns=['rank'])

