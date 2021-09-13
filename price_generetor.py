import random
random.seed(1)

gen_txt = open("gen_prices.txt", "w")

for i in range(2000):
    temp = (250 - random.random()*10)
    gen_txt.write(f'{temp:.5f}'+"\n")

print("Preços gerados!\n")

gen_txt.close()