import System.IO


-----Tarefas-----

--Tarefa1
tarefa1 :: IO()
tarefa1 = do
    conteudoDisciplina <- readFile "ucs.txt"
    conteudoInscricao <- readFile "inscricoes.txt"
    conteudoAlunos <- readFile "listaalunos.txt"
    printDisciplinas (lines conteudoDisciplina) (lines conteudoInscricao) (lines conteudoAlunos)

--Tarefa2
tarefa2 :: IO()
tarefa2 = do
    conteudoDisciplina <- readFile "ucs.txt"
    conteudoInscricao <- readFile "inscricoes.txt"
    conteudoAlunos <- readFile "listaalunos.txt"
    printNomes (lines conteudoAlunos) (lines conteudoInscricao) (lines conteudoDisciplina)

--tarefa3
tarefa3 :: IO()
tarefa3 = do
    conteudoDisciplina <- readFile "ucs.txt"
    conteudoInscricao <- readFile "inscricoes.txt"
    conteudoAlunos <- readFile "listaalunos.txt"
    putStrLn "indique o nome da disciplina"
    disciplina <- getLine
    printDisciplinas_input disciplina (lines conteudoDisciplina) (lines conteudoInscricao) (lines conteudoAlunos)

--tarefa4
tarefa4 :: IO()
tarefa4 = do
    conteudoDisciplina <- readFile "ucs.txt"
    conteudoInscricao <- readFile "inscricoes.txt"
    conteudoAlunos <- readFile "listaalunos.txt"
    putStrLn "indique o nome do aluno"
    aluno <- getLine
    printNomes_input aluno (lines conteudoAlunos) (lines conteudoInscricao) (lines conteudoDisciplina)

--Tarefa5
tarefa5 :: IO()
tarefa5 = do 
    putStrLn " "
    putStrLn "-----Menu-----"
    putStrLn "1-Tarefa1"
    putStrLn "2-Tarefa2"
    putStrLn "3-Tarefa3"
    putStrLn "4-Tarefa4"
    putStrLn "0-Sair"
    putStrLn "indique a opcao 0 a 4"
    putStrLn "--------------"

    opcao <-getLine
    menu opcao
    if opcao /= "0"
        then tarefa5
        else return()
    
-------Funcoes utilizadas nas tarefas-------
--Funcoes tarefa5

menu :: String -> IO()
menu string 
    |string == "0" = putStrLn "Terminou tarefa5"
    |string == "1" = tarefa1
    |string == "2" = tarefa2
    |string == "3" = tarefa3
    |string == "4" = tarefa4
    |otherwise = putStrLn "Opcao invalida"

--Funcoes tarefa4
printNomes_input ::String-> [String] -> [String] -> [String]-> IO() 
printNomes_input w [] y x = return ()
printNomes_input input conteudo_alunos conteudo_insc conteudo_disc= do

    putStrLn ("-----"++ input ++ "-----") -- dar print ao nome da disciplina
    encontrarAlxxx input conteudo_alunos conteudo_insc conteudo_disc--numero da disciplina

encontrarAlxxx:: String -> [String] -> [String] -> [String]-> IO() --descobre o al a partir do nome do aluno
encontrarAlxxx x [] y z = return()
encontrarAlxxx input (linha:linhas) conteudo_insc conteudo_disc = do
    let numero_al = head (words linha)
    if input == unwords (tail(tail(words linha)))
        then  descobrirNumero numero_al conteudo_insc conteudo_disc --funcao usada na tarefa 2 com al diz o numero das disciplinas
        else return()
    encontrarAlxxx input linhas conteudo_insc conteudo_disc

---Funcoes tarefa3 
printDisciplinas_input :: String -> [String] -> [String] -> [String]-> IO() -- da print apenas no nome da uc
printDisciplinas_input w [] y x = return ()
printDisciplinas_input input conteudo_disc conteudo_insc conteudo_alunos= do

    putStrLn ("-----"++ input ++ "-----") -- dar print ao nome da disciplina
    encontrarNome input conteudo_disc conteudo_insc conteudo_alunos


encontrarNome:: String -> [String] -> [String] -> [String]-> IO() --descobre o numero da disciplina a partir do nome
encontrarNome x [] y z = return()
encontrarNome input (linha:linhas) conteudo_insc conteudo_alunos = do
    let numero = head (words linha)
    if input == unwords (tail(tail(words linha)))
        then descobrirAlxxx numero conteudo_insc conteudo_alunos --funcao usada na tarefa 1, com o numero descobre o al
        else return()
    encontrarNome input linhas conteudo_insc conteudo_alunos


---Funcoes Tarefa2
printNomes :: [String] -> [String] -> [String]-> IO() 
printNomes [] y x = return ()
printNomes (linha:linhas) conteudo_insc conteudo_dis= do

    putStrLn ("-----"++ unwords(tail(tail (words linha))) ++ "-----") -- dar print ao nome da disciplina
    let numero_al = head (words linha) --numero da disciplina

   
    descobrirNumero numero_al conteudo_insc conteudo_dis  -- descobrir numero usando al
    printNomes linhas conteudo_insc conteudo_dis-- print proxima disciplina

descobrirNumero:: String -> [String] -> [String]-> IO() --descobre o numero a partir do al
descobrirNumero numero_al [] conteudo_disc = return()
descobrirNumero numero_al (linha:linhas) conteudo_disc = do
    let numero_al2 = last (words linha) -- al do aluno
    if head (words linha) == numero_al
        then descobrirUc numero_al2 conteudo_disc --numero em UC
        else return ()
    descobrirNumero numero_al linhas conteudo_disc

descobrirUc :: String -> [String] -> IO() --descobre a UC a partir do numero
descobrirUc numero_al2 [] = return()
descobrirUc numero_al2 (linha:linhas) = do
    if head (words linha) == numero_al2
        then putStrLn (unwords (tail (tail(words linha)))) --dar print no nome da UC
        else return()
    descobrirNome numero_al2 linhas

----Funcoes Tarefa1
printDisciplinas :: [String] -> [String] -> [String]-> IO() -- da print apenas no nome da uc
printDisciplinas [] y x = return ()
printDisciplinas (linha:linhas) conteudo_insc conteudo_alunos= do

    putStrLn ("-----"++ unwords(tail(tail (words linha))) ++ "-----") -- dar print ao nome da disciplina
    let numero = head (words linha) --numero da disciplina

    descobrirAlxxx numero conteudo_insc conteudo_alunos  -- descobrir al usando numero
    printDisciplinas linhas conteudo_insc conteudo_alunos -- print proxima disciplina


descobrirAlxxx:: String -> [String] -> [String]-> IO() --descobre o al a partir do numero da disciplina
descobrirAlxxx numero [] conteudo_alunos = return()
descobrirAlxxx numero (linha:linhas) conteudo_alunos = do
    let numero_al = head (words linha) -- al do aluno
    if last (words linha) == numero
        then descobrirNome numero_al conteudo_alunos --tranforma al em nome
        else return ()
    descobrirAlxxx numero linhas conteudo_alunos

descobrirNome :: String -> [String] -> IO() --descobre o nome a partir do al
descobrirNome al [] = return()
descobrirNome al (linha:linhas) = do
    if head (words linha) == al
        then putStrLn (unwords (tail (tail(words linha)))) --dar print no nome
        else return()
    descobrirNome al linhas

    
    
    
    
    
    
