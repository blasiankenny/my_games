import csv

with open("st.csv","r") as f:
    r = csv.reader(f,delimiter=",")
    for row in r:
        print(",".join(row))

with open("st.txt", "r") as f:
    r = csv.reader(f,delimiter=",")
    for row in r:
        print(",".join(row))