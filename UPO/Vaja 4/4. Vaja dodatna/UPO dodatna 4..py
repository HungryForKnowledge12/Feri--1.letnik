import matplotlib.pyplot as plt
import random

vektor = []
for _ in range(10):
    vektor.append(random.uniform(0, 10))

def povprecje(vektor):
    sestevek = sum(vektor)
    st_stevil = len(vektor)
    return sestevek / st_stevil

def standardna_deviacija(vektor):
    avrg = povprecje(vektor)
    sestevek_kvadratov = 0
    for x in vektor:
        razlika = x - avrg
        kvadrat_razlike = razlika ** 2
        sestevek_kvadratov += kvadrat_razlike
    st_vseh = len(vektor)
    varianca = sestevek_kvadratov / (st_vseh - 1)
    std_dev = varianca ** 0.5
    return std_dev

def izrisi_vektor(vektor):
    avrg = povprecje(vektor)
    deviacija = (standardna_deviacija(vektor))

    plt.figure()
