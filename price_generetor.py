import random
random.seed(1)

gen_txt = open("gen_prices.txt", "w")

for i in range(500):
    temp = (250 - random.random()*10)
    gen_txt.write(str(temp)+"\n")

print("Preços gerados!\n")

gen_txt.close()