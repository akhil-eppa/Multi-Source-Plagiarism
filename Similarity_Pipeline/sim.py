# -*- coding: utf-8 -*-
"""
Created on Thu Nov  5 15:44:04 2020

@author: Akhil
"""
from scipy import spatial
import pickle
from math import *
def jaccard_sim(x,y):
    x=[round(i,1) for i in x]
    y=[round(i,1) for i in y]
    intersection_cardinality = len(set.intersection(*[set(x), set(y)]))
    union_cardinality = len(set.union(*[set(x), set(y)]))
    return intersection_cardinality/float(union_cardinality)
def jaccard_sim_modified (x,y):
    #x=[round(i,1) for i in x]
    #y=[round(i,1) for i in y]
    intersection=0
    for i in range(len(x)):
        if abs(x[i]-y[i])<0.33:
            intersection+=1
    x=[round(i,1) for i in x]
    y=[round(i,1) for i in y]
    intersection_cardinality = len(set.intersection(*[set(x), set(y)]))
    union_cardinality = len(set.union(*[set(x), set(y)]))
    return intersection_cardinality/float(union_cardinality)
def cosine_sim(v1,v2):
    c=0
    l1=0
    l2=0
    for i in range(len(v1)):
       c+= v1[i]*v2[i]
       l1+= (v1[i])**2
       l2+= (v2[i])**2
    result = c/((l1**0.5)*(l2**0.5))
    #result = 1 - spatial.distance.cosine(v1, v2)
    return result

def get_mapping(dict1,dict2):
    #dict 1 is programs, functions and respective vectors
    #dict2 is programs, functions and respective length of functions
    mapping=dict()#final dictionary to return
    #Iterating through all programs in dict1
    for i in dict1.keys():
        #sim_scores stores the highest similarity it found for a particular function in a program
        sim_scores=dict()
        #sim_progs stores the corresponding program in which the given function found another function with the highest match
        sim_progs=dict()
        #Initializing the 2 dictionaries
        for k in dict1[i].keys():
            sim_scores[k]=0
            sim_progs[k]=""
        #Iterating through all the other programs for comparision purposes
        for j in dict1.keys():
            #We do not want to compare the same program with itself. So only if i!=j proceed further
            if (i!=j):
                #outer iterates through all functions in program 1
                for outer in dict1[i].keys():
                    #inner iterates through all functions in program 2
                    for inner in dict1[j].keys():
                        #find the cosine similarity between particular function in program 1 to another function in program 2
                        similarity=jaccard_sim_modified(dict1[i][outer],dict1[j][inner])
                        #if the similarity score found is greater than previously stored one then we need to update
                        if similarity>sim_scores[outer]:
                            #updating highest similarity score for a function
                            sim_scores[outer]=similarity
                            #update mapping as to which program the other function belongs to
                            sim_progs[outer]=j
        sum=0
        lines=0
        sources=[]
        '''
        Formula used to generate final similarity score for given program based on similarity scores
        for various functions is
        Similarity Score = Sigma[i=1 to n](Si*Li) / Sigma[i= 1 to n](Li)
        Here Si is highest similarity score for a function i in a program
        Here Li is the number of lines that function i has.
        '''
        for k in sim_scores.keys():
            sum+=sim_scores[k]*dict2[i][k]
            lines+=dict2[i][k]
            if sim_progs[k] not in sources:
                sources.append(sim_progs[k])
        final_score=sum/lines
        '''
        Final dictionary returned is such that the keys are the program names.
        Value is a list in which first element is the similarity score and the remaining elements
        are all the source programs from which the plagiarism could have occurred.
        '''
        final_list=[final_score]+sources
        mapping[i]=final_list
    return mapping
a = pickle.load(open("func_vec_map.pkl", "rb"))
b = pickle.load(open("func_line_map.pkl", "rb"))
#print(a)
#print(b)
map=get_mapping(a,b)
for i in map.keys():
    print(i,"->",map[i])
