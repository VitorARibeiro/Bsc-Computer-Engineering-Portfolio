#  Protocolo de Trabalho B2
# Grupo de Trabalho: César Faria, Diana Costa, João Azevedo, Leonor Pinto e Vitor Ribeiro
# PL3 - Docente Paulo Martins

#Proposta de solução Pergunta 1
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, accuracy_score
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score



# Carregar o DataFrame
DataFrame = pd.read_csv("./ObesityDataSet_raw_and_data_sinthetic.csv")

# Filtrar apenas os meios de transporte especificados
filtros = ['Motorbike', 'Public_Transportation', 'Walking']
DataFrame_filtrado = DataFrame[DataFrame['MTRANS'].isin(filtros)]

# Guardar novo DataFrame
DataFrame_filtrado.to_csv("filtered_transport.csv", index=False)



#Proposta de solução Pergunta 2

# Gráfico de barras
plt.figure(1 ,figsize=(10,6))
sns.countplot(data=DataFrame_filtrado, x='Age', hue='MTRANS')
plt.title('Distribuição de pessoas por idade e meio de transporte')
plt.xlabel('Idade')
plt.ylabel('Número de pessoas')
plt.legend(title='Meio de Transporte')
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()



#Proposta de solução pergunta 3
# Filtrar dados
fem = DataFrame[(DataFrame['Gender'] == 'Female') & (DataFrame['Age'] >= 25) & (DataFrame['Age'] <= 45)]
calc_counts = fem['CALC'].value_counts()

# Gráfico circular
plt.figure(2, figsize=(8,8))
plt.pie(calc_counts, labels=calc_counts.index, autopct='%1.1f%%', startangle=140)
plt.title('Consumo de álcool (Mulheres 25-45 anos)')
plt.axis('equal')
plt.show()


#Proposta de solução pergunta 4
def peso_minimo(genero, idade):
    sub_DataFrame = DataFrame[(DataFrame['Gender'] == genero) & (DataFrame['Age'] == idade)]
    if sub_DataFrame.empty:
        return "Sem dados para essa combinação."
    
    peso_min = sub_DataFrame['Weight'].min()
    caec = sub_DataFrame[sub_DataFrame['Weight'] == peso_min]['CAEC'].values[0]
    return f"Peso mínimo: {peso_min}kg, CAEC: {caec}"

# Exemplo de uso
print(peso_minimo("Male", 30))


#Pergunta 5
feminino=DataFrame[(DataFrame['Gender']=='Female')]

X=feminino[['Age']];
Y=feminino[['Weight']];

modelo=LinearRegression();

modelo.fit(X,Y)
y_pred=modelo.predict(X)


plt.figure(figsize=(10,6))
plt.scatter(feminino['Age'], feminino['Weight'], alpha=0.5, label='Dados reais')


plt.plot(feminino['Age'], y_pred, color='red', label="Regressão Linear")

plt.title('Relação entre Idade e Peso (Género Feminino)')
plt.xlabel('Idade')
plt.ylabel('Peso (kg)')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# Erros
mae = mean_absolute_error(feminino['Weight'], y_pred)
mse = mean_squared_error(feminino['Weight'], y_pred)
rmse = mean_squared_error(feminino['Weight'], y_pred, squared=False)
r2 = r2_score(feminino['Weight'], y_pred)

print(f"MAE (Erro Absoluto Médio): {mae:.2f}")
print(f"MSE (Erro Quadrático Médio): {mse:.2f}")
print(f"RMSE (Raiz do Erro Quadrático Médio): {rmse:.2f}")
print(f"R² (Coeficiente de Determinação): {r2:.2f}")


#Pergunta 6
df_ml = DataFrame[['FAVC', 'FCVC', 'MTRANS', 'NObeyesdad']].copy()

# Codificar variáveis categóricas com LabelEncoder
#Transforma colunas com strings em numeros
le = LabelEncoder()

df_ml['FAVC'] = le.fit_transform(df_ml['FAVC'])
df_ml['MTRANS'] = le.fit_transform(df_ml['MTRANS'])
df_ml['NObeyesdad'] = le.fit_transform(df_ml['NObeyesdad'])  # target

X = df_ml[['FAVC', 'FCVC', 'MTRANS']]  # Features
y = df_ml['NObeyesdad']                # Target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Criar e treinar o modelo
modelo = RandomForestClassifier(n_estimators=100, random_state=42)
modelo.fit(X_train, y_train)

# Previsões
y_pred = modelo.predict(X_test)

# Avaliação
print("Precisão:", accuracy_score(y_test, y_pred))
print("\nRelatório de classificação:")
print(classification_report(y_test, y_pred))
