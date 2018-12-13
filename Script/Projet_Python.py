#! /usr/bin/env python 2.7
# -*- coding: utf-8 -*-
"""
Created on 12/09/2018

@author: DENIAUD B. & BERNE M.
"""

# Import des packages nécessaire au fonctionnement du script
import os,sys,re


#Saisir le chemin d'accès au repertoire contenant les séquences dans la variable repertory.
repertory='/comptes/E117951H/Desktop/Master 2/Python/Projet_python
'


print(" ______________________________________________________________________________")
print("|                         Fonctionnement du Script                             |")
print("|                                                                              |")
print("| Après la définition du répertoire de travail (contenant les séquences fasta) |")
print("| la procédure my_network procède en 4 étapes :                                |")
print("|                                                                              |")
print("|    1- Lecture du fichier avec les séquences fasta DANS LE DOSSIER SEQUENCES  |")
print("|    2- Alignement des séquences et calcul d'un score                          |")
print("|    3- Création d'un network d'alignement des gènes selon le score.           |")
print("|    4- Enregistrement éventuel du network sous format PDF et GEXF             |")
print("|                                                                              |")
print("| Notes sur le graphique :                                                     |")
print("| L'épaisseur des liens dépend du score et le diamètre des noeuds de la taille |")
print("| de la séquence                                                               |")
print("|                                                                              |")
print("| L'appel de la procédure se fait à la fin et ne necessite aucun paramètres.   |")
print("| Elle crée un fichier pdf où sera stocké le network en format d'image         |")
print("| vectorielle pour une meilleure résolution d'image                            |")
print("|                                                                              |")
print("| RAPPEL : les séquences ne doivent contenirs que les bases ATCG en majuscules |")
print("|______________________________________________________________________________|")

#####################################DEBUT##############################################

###########################Définition du fichier de séquences###########################

# Vérification de l'éxistance du répertoire de travail et création de la variable correspondante
if(os.path.exists(repertory)):
    os.chdir(repertory)
    cwd=os.getcwd()


# Le script est stoppé avec un message d'erreur au cas ou ce répertoire n'éxiste pas
else:
    sys.exit("Modifiez le chemin d'accès dans la variable repertory du fichier, le chemin d'accès actuel n'existe pas ")


# Définition d'une fonction de création de répertoire pour les sauvegardes des fichiers de sortie
def my_mkdir(name):
    if not os.path.exists(name):
        os.mkdir(name)
    assert os.path.isdir(name)


# Création du dossier "sequences" où le script ira chercher les séquences fasta
my_mkdir("sequences")
my_doc_in_repertory=os.listdir(os.path.join(cwd,"sequences"))
print('\n\nVeuillez déposer les séquences fasta à utiliser dans le sous-repertoire "sequences" pour le bon fonctionnement du script')


# Vérification de l'éxistance d'un fichier fasta dans le sous répertoire de travail, le script est stoppé avec un message d'erreur si le repertoire est vide
if(len(my_doc_in_repertory)==0):
    sys.exit('\n\n Il y a aucun fichier dans le repertoire sequence, veuillez mettre vos fasta dans ce dossier')


# Définition de la fonction de création du Network
def my_network():


# Initialisation de 2 listes pour le stockages des séquences et de leurs noms
    seq=[]
    nom=[]
    sequences=''


# La variable myseq sert à concatèner les séquences des gènes présentes sur plusieurs lignes
    myseq=''
    choix=raw_input('Souhaitez vous utiliser votre fichier fasta présent dans le dossier "sequences" ? (Y/N) \n\n')
    if(choix=='Y' or choix=='yes' or choix=='Yes' or choix=='O' or choix=='y' or choix=='oui' or choix=='Oui' or choix=='o'):


# Le script intérroge l'utilisateur pour connaitre le nombre de séquences à utiliser
        nb_fichier=raw_input('Saisir le nombre de fichiers fasta à lire (maximum 10) \n\n')
    else:
        nb_fichier='1'
    j=0


# On fixe le nombre max de fichiers fasta à lire à 10
    if int(nb_fichier)>10:
        nb_fichier='10'
        print('Vous pourrez utiliser seulement '+nb_fichier+' fichiers, le nombre saisi est trop grand \n\n')
    while (j<len(range(int(nb_fichier)))):
        j=j+1
        if(choix=='Y' or choix=='yes' or choix=='Yes' or choix=='O' or choix=='y' or choix=='oui' or choix=='Oui' or choix=='o'):


# Le fichier de séquences est renseigné par l'utilisateur
            Fasta_name=raw_input('Saisir le nom du fichier fasta \n\n')
        else:


# Si l'utilisateur ne souhaite pas renseigner des séquences, le fichier par défaut est utilisé pour le reste du script
            print("La séquences par défaut va être utilisé ;)")
            Fasta_name='sequences.txt'


# On ouvre le fichier (en lecture seule) avec les sequences fasta si le chemin d'accès au fichier est correct (si le fichier existe)
        if(os.path.exists(os.path.join(cwd,"sequences",Fasta_name))):
            sequences=open(os.path.join(cwd,"sequences",Fasta_name),"r")
        else:


# Si le fichier est mal placé dans l'arborescence, on arrête le script en alertant l'utilisateur du problème
            print('\n\nERREUR: Le fichier demandé n\'existe pas ou n\'est pas placé dans le repertoire sequences \n')
            sys.exit("Mettez vos séquences dans le fichier séquences")


###########################Lecture de la séquences######################################


# i est un controle pour ne pas inclure de séquence vide au début de la liste seq
        i=0
        for line in sequences:


# On récupère le nom du gène après le chevron ">"
            gene=len(re.findall(r"[>]",line))
            if(gene>0):


# On remplit la liste "seq" par la séquence récupérée, sauf au premier tour de boucle qui ne contient pas de séquences
                if(i!=0):
                    seq.append(myseq)
                myseq=''
                gene=0


# La liste "nom" stocke les noms des gènes
                nom.append(line[1:-1])
                i=i+1
            else:


# On concatène toutes les lignes d'acides nucléiques jusqu'à arriver au prochain gène (chevron ">")
                myseq=myseq+line[:-1]


# On obtient nos séquences et les noms des gènes en listes, on ferme le fichier
        seq.append(myseq)
        sequences.close



########################Réalisation de l'alignement deux à deux#########################

# Utilisation de l'algorithme de NeedleMan Et Wunch avec package Biopython: pairwise2 pour un alignement deux à deux
    import numpy as np
    from Bio import pairwise2


# Réalisation du premier alignement pour récupérer les scores (seuil=moyenne score+0.5*ecart-type) grâce à la librairie numpy
    score=[]
    for i in range(len(seq)):
        for j in range((i+1),len(seq)):


# Règle d'alignement : Alignement: Score = +3pts si caractère identique,-2pts si caractère different, -1pt si gap créé et -0.5pt si gap étendu
            score.append(pairwise2.align.globalms(seq[i],seq[j], 3, -2, -1, -.5,score_only=True))


# Récupération d'une liste de tuples de gènes où le score d'alignement est supérieur au seuil, gènes dont l'alignement deux à deux a un score supérieur au seuil
    my_list=[]
    print('\nLa moyenne des scores vaut '+str(round(np.mean(score),2))+' \n\n')


# On fixe le seuil à la moyenne+0.05*écart-type des scores recueillis par défaut, sauf si l'utilisateur veut saisir un seuil.
    choix_seuil=raw_input('Souhaitez vous saisir vous même le seuil, sinon le score sera approximé avec la moyenne des scores des alignements (Y/N) \n\n')
    if(choix_seuil=='Y' or choix_seuil=='yes' or choix_seuil=='Yes' or choix_seuil=='O' or choix_seuil=='y' or choix_seuil=='oui' or choix_seuil=='Oui' or choix_seuil=='o'):
        seuil=float(raw_input('Saisir la valeur du seuil: \nRappel : Score = +3pts si caractère identique, -2pts si caractère different, -1pt si gap créé et -0.5pt si gap étendu \n\n'))
    else:
        seuil=(np.mean(score)+0.05*np.std(score))
        print('\n\nLe seuil par défaut utilisé vaut: moyenne + 0.05*sd = '+str(round(seuil,2))+'\n\n')


# Création d'un indice pour parcourir le tableau des scores
    indice=0


# Création d'un dictionnaire avec les liens conservés (score>seuil) et les scores correspondant
    edge_labels={}
    for i in range(len(seq)):
        for j in range((i+1),len(seq)):


# Récupération des scores d'alignement, un lien est présent si le score est supérieur à la moyenne calculée précédemment
            if(score[indice]>seuil):


# Création d'un dictionnaire, les clés sont contenues liste de tuples de gènes dont le score est supérieur au seuil
                my_list.append((nom[i],nom[j]))
                edge_labels[(nom[i],nom[j])]=score[indice]


# Incrémentation de l'indice pour l'alignement suivant
            indice=indice+1


# En fin de boucle le script contient une liste de tuples de gènes avec les liens à réaliser
# Au cas ou le score est supérieur au seuil, il y effectivement un lien entre les deux séquences


#################################Création du graphique##################################

# Réalisation d'un graphique avec la librairie networkx
    import networkx as nx
    Graph=nx.Graph()


# Ajout des noms de gènes comme noeuds
    Graph.add_nodes_from(nom)


# Ajout des liens définis auparavant
    Graph.add_edges_from(my_list)


# Récupération des positions de chaques noeuds et liens dans le graphique
    pos=nx.spring_layout(Graph)


# Le diamètre des noeuds est affiché de manoières croissante en fonction de la longueur des séquences (20*log(taille))
    node_s=[]
    for t in range(len(seq)):
        node_s.append(20*np.log(len(seq[t])))
    nx.draw_networkx_nodes(Graph,pos,node_color='green',label=True,alpha=1,node_size=node_s)


# Width augmente l'épaisseur des liens en plus de la présence des labels indiquant le score (utilisation du Log10 et de division pour obtenir des valeurs réduites)
# Ceci dans le but de limiter les liens d'épaisseur surdimensionnées.
# On crée un dictionnaire indépendant du premier pour conserver les scores d'alignement et les afficher
    Width=dict(edge_labels)
    for key,value in Width.items() : Width[key] = np.log10(value)/2
    nx.draw_networkx_edges(Graph,pos,width=Width.values(),style='solid',edge_color='red',alpha=1)


# Legendes des noeuds et liens, taille et couleur controlées par font_size et font_color
    nx.draw_networkx_edge_labels(Graph,pos,edge_labels=edge_labels,font_size=2,alpha=0.5,font_color='black')
    nx.draw_networkx_labels(Graph,pos,font_size=3,font_color='blue')


# Création d'un graphique avec la librairie matplotlib
    import matplotlib.pyplot as plt
    save=raw_input('Vous voulez exporter la figure (Y/N) \n \n')



##################################Export du graphique###################################

# Réalisation du graphique et export dans le repertoire "figures" et "data_gexf" si l'utilisateur le souhaite
    my_mkdir("figures")
    my_mkdir("data_gexf")
    if (save=='Y' or save=='yes' or save=='Yes' or save=='O' or save=='y' or save=='oui' or save=='Oui' or save=='o'):
        doc_name=raw_input('Saisir le nom du pdf à créer, sans l\'extension .pdf \n \n')


# Format pdf pour sauvegarder les images au format vectoriel et non bitmap, cela permet une meilleure qualité d'image
        plt.savefig(os.path.join(cwd,"figures",doc_name)+'.pdf')


# Export dans un fichier gexf des nodes et edges réalisés
        nx.write_gexf(Graph,os.path.join(cwd,"data_gexf",doc_name)+'.gexf')


# Fin de la procédure
# Appel de la procédure pour simplifier l'utilisation du code par l'appel d'une procédure
my_network()

raw_input("Appuyer sur une touche pour terminer le programme. ")









































#                    .+~                :xx++::
#                   :`. -          .!!X!~"?!`~!~!. :-:.
#                  {             .!!!H":.~ ::+!~~!!!~ `%X.
#                  '             ~~!M!!>!!X?!!!!!!!!!!...!~.
#                              {!:!MM!~:XM!!!!!!.:!..~ !.  `{
#                  {: `   :~ .:{~!!M!XXHM!!!X!XXHtMMHHHX!  ~ ~
#                ~~~~{' ~!!!:!!!!!XM!!M!!!XHMMMRMSXXX!!!!!!:  {`
#                  `{  {::!!!!!X!X?M!!M!!XMMMMXXMMMM??!!!!!?!:~{
#               : '~~~{!!!XMMH!!XMXMXHHXXXXM!!!!MMMMSXXXX!!!!!!!~
#            :    ::`~!!!MMMMXXXtMMMMMMMMMMMHX!!!!!!HMMMMMX!!!!!: ~
#               '~:~!!!!!MMMMMMMMMMMMMMMMMMMMMMXXX!!!M??MMMM!!X!!i:
#               {~{!!!!!XMMMMMMMMMMMM8M8MMMMM8MMMMMXX!!!!!!!!X!?t?!:
#               ~:~~!!!!?MMMMMM@M@RMRRR$@@MMRMRMMMMMMXSX!!!XMMMX{?X!
#             :XX {!!XHMMMM88MM88BR$M$$$$8@8RN88MMMMMMMMHXX?MMMMMX!!!
#           .:X! {XMSM8M@@$$$$$$$$$$$$$$$$$$$B8R$8MMMMMMMMMMMMMMMMX!X
#          :!?! !?XMMMMM8$$$$8$$$$$$$$$$$$$$BBR$$MMM@MMMMMMMMMMMMMM!!X
#        ~{!!~ {!!XMMMB$$$$$$$$$$$$$$$$$$$$$$$$MMR$8MR$MMMMMMMMMMMMM!?!:
#       :~~~ !:X!XMM8$$$$$$$$$$$$$$$$$$$$$$$RR$$MMMMR8NMMMMMMMMMMMMM{!`-
#    ~:{!:~`~':!:HMM8N$$$$$$$$$$$$$$$$$$$$$$$$$8MRMM8R$MRMMMMMMMMRMMMX!
#  !X!``~~   :~XM?SMM$B$$$$$$$$$$$$$$$$$$$$$$BR$$MMM$@R$M$MMMMMM$MMMMX?L
# X~.      : `!!!MM#$RR$$$$$$$$$$$$$$$$$R$$$$$R$M$MMRRRM8MMMMMMM$$MMMM!?:
# ! ~ {~  !! !!~`` :!!MR$$$$$$$$$$RMM!?!??RR?#R8$M$MMMRM$RMMMM8MM$MMM!M!:>
#: ' >!~ '!!  !   .!XMM8$$$$$@$$$R888HMM!!XXHWX$8$RM$MR5$8MMMMR$$@MMM!!!{ ~
#!  ' !  ~!! :!:XXHXMMMR$$$$$$$$$$$$$$$$8$$$$8$$$MMR$M$$$MMMMMM$$$MMM!!!!
# ~{!!!  !!! !!HMMMMMMMM$$$$$$$$$$$$$$$$$$$$$$$$$$MMM$M$$MM8MMMR$$MMXX!!!!/:`
#  ~!!!  !!! !XMMMMMMMMMMR$$$$$$$$$$$$R$RRR$$$$$$$MMMM$RM$MM8MM$$$M8MMMX!!!!:
#  !~ ~  !!~ XMMM%!!!XMMX?M$$$$$$$$B$MMSXXXH?MR$$8MMMM$$@$8$M$B$$$$B$MMMX!!!!
#  ~!    !! 'XMM?~~!!!MMMX!M$$$$$$MRMMM?!%MMMH!R$MMMMMM$$$MM$8$$$$$$MR@M!!!!!
#  {>    !!  !Mf x@#"~!t?M~!$$$$$RMMM?Xb@!~`??MS$M@MMM@RMRMMM$$$$$$RMMMMM!!!!
#  !    '!~ {!!:!?M   !@!M{XM$$R5M$8MMM$! -XXXMMRMBMMM$RMMM@$R$BR$MMMMX??!X!!
#  !    '!  !!X!!!?::xH!HM:MM$RM8M$RHMMMX...XMMMMM$RMMRRMMMMMMM8MMMMMMMMX!!X!
#  !     ~  !!?:::!!!MXMR~!MMMRMM8MMMMMS!!M?XXMMMMM$$M$M$RMMMM8$RMMMMMMMM%X!!
#  ~     ~  !~~X!!XHMMM?~ XM$MMMMRMMMMMM@MMMMMMMMMM$8@MMMMMMMMRMMMMM?!MMM%HX!
#           !!!!XSMMXXMM .MMMMMMMM$$$BB8MMM@MMMMMMMR$RMMMMMMMMMMMMMMMXX!?H!XX
#           XHXMMMMMMMM!.XMMMMMMMMMR$$$8M$$$$$M@88MMMMMMMMMMMMMMM!XMMMXX!!!XM
#      ~   {!MMMMMMMMRM:XMMMMMMMMMM8R$$$$$$$$$$$$$$$NMMMMMMMM?!MM!M8MXX!!/t!M
#      '   ~HMMMMMMMMM~!MM8@8MMM!MM$$8$$$$$$$$$$$$$$8MMMMMMM!!XMMMM$8MR!MX!MM
#          'MMMMMMMMMM'MM$$$$$MMXMXM$$$$$$$$$$$$$$$$RMMMMMMM!!MMM$$$$MMMMM{!M
#          'MMMMMMMMM!'MM$$$$$RMMMMMM$$$$$$$$$$$$$$$MMM!MMMX!!MM$$$$$M$$M$M!M
#           !MMMMMM$M! !MR$$$RMM8$8MXM8$$$$$$$$$$$$NMMM!MMM!!!?MRR$$RXM$$MR!M
#           !M?XMM$$M.{ !MMMMMMSUSRMXM$8R$$$$$$$$$$#$MM!MMM!X!t8$M$MMMHMRMMX$
#    ,-,   '!!!MM$RMSMX:.?!XMHRR$RM88$$$8M$$$$$R$$$$8MM!MMXMH!M$$RMMMMRNMMX!$
#   -'`    '!!!MMMMMMMMMM8$RMM8MBMRRMR8RMMM$$$$8$8$$$MMXMMMMM!MR$MM!M?MMMMMM$
#          'XX!MMMMMMM@RMM$MM@$$BM$$$M8MMMMR$$$$@$$$$MM!MMMMXX$MRM!XH!!??XMMM
#          `!!!M?MHMMM$RMMMR@$$$$MR@MMMM8MMMM$$$$$$$WMM!MMMM!M$RMM!!.MM!%M?~!
#           !!!!!!MMMMBMM$$RRMMMR8MMMMMRMMMMM8$$$$$$$MM?MMMM!f#RM~    `~!!!~!
#           ~!!HX!!~!?MM?MMM??MM?MMMMMMMMMRMMMM$$$$$MMM!MMMM!!
#           '!!!MX!:`~~`~~!~~!!!!XM!!!?!?MMMM8$$$$$MMMMXMMM!!
#            !!~M@MX.. {!!X!!!!XHMHX!!``!XMMMB$MM$$B$M!MMM!!
#            !!!?MRMM!:!XHMHMMMMMMMM!  X!SMMX$$MM$$$RMXMMM~
#            !M!MMMM>!XMMMMMMMMXMM!!:!MM$MMMBRM$$$$8MMMM~
#             `?H!M$R>'MMMM?MMM!MM6!X!XM$$$MM$MM$$$$MX$f
#              `MXM$8X MMMMMMM!!MM!!!!XM$$$MM$MM$$$RX@"
#               ~M?$MM !MMMMXM!!MM!!!XMMM$$$8$XM$$RM!`
#                !XMMM !MMMMXX!XM!!!HMMMM$$$$RH$$M!~
#                'M?MM `?MMXMM!XM!XMMMMM$$$$$RM$$#
#                 `>MMk ~MMHM!XM!XMMM$$$$$$BRM$M"
#                  ~`?M. !M?MXM!X$$@M$$$$$$RMM#
#                    `!M  !!MM!X8$$$RM$$$$MM#`
#                      !% `~~~X8$$$$8M$$RR#`
#                       !!x:xH$$$$$$$R$R*`
#                        ~!?MMMMRRRM@M#`
#                         `~???MMM?M"`
#                             ``~~
#
