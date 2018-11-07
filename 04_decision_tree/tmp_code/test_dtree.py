from math import log

import operator

def createDataset():
    dataset = [[1,1,'yes'],
               [1,1,'yes'],
               [1,0,'no'],
               [0,1,'no'],
               [0,1,'no']]
    labels = ['no surfacing','flippers']
    return dataset,labels


def calcShannonEnt(dataset):
    numEntries = len(dataset)
#     print('numEntries',numEntries)
    labelCounts = {}
    for featVec in dataset:
        currentLabel = featVec[-1]
        if currentLabel not in labelCounts.keys():labelCounts[currentLabel] = 0
        labelCounts[currentLabel] += 1
        shannonEnt = 0.0
    for key in labelCounts:
        prob = float(labelCounts[key])/numEntries
        shannonEnt -= prob*log(prob,2)
    return shannonEnt


def spiltDataset(dataset,axis,value):
    retDataset = []
    for featVec in dataset:
        if featVec[axis] == value:
            reducedFeatVec = featVec[:axis]
#             print('raw reducedFeatVec\n',reducedFeatVec)
            reducedFeatVec.extend(featVec[axis+1:])
#             print('afer extend reducedFeatVec\n',reducedFeatVec)
            retDataset.append(reducedFeatVec)
#             print('retDataset',retDataset)
    return retDataset


def majorityCnt(classList):
    classCount = {}
    for vote in classList:
        if vote not in classCount.keys():classCount[vote]=0
        classCount[vote] += 1
    # print('key',operator.itemgetter(0))
    sortedClassCount = sorted(classCount.items(),key=operator.itemgetter(1),
                             reverse=True)
    # print('classCount',classCount)
    # print('sortedClassCount',sortedClassCount)
    return sortedClassCount[0][0]


def chooseBestFeatureToSplit(dataset):
    numFeatures = len(dataset[0])-1
    print('numFeatures',numFeatures)
    baseEntropy = calcShannonEnt(dataset)
    print('raw baseEntropy',baseEntropy)
    bestInfoGain = 0.0
    bestFeature = -1
    for i in range(numFeatures):
        # print('i',i)
        featList = [example[i] for example in dataset]
        # print('featList',featList)
        uniqueVals = set(featList)
        # print('uniqueVals',uniqueVals)
        newEntropy = 0.0
        for value in uniqueVals:
            subDataset = spiltDataset(dataset,i,value)
            # print('subDataset',subDataset)
            prob = len(subDataset)/float(len(dataset))
            # print('prob',prob)
            newEntropy += prob*calcShannonEnt(subDataset)
        infoGain = baseEntropy - newEntropy
        # print('infoGain',infoGain)
        if(infoGain > bestInfoGain):
            bestInfoGain = infoGain
            bestFeature = i
    return bestFeature 


def createTree(dataset,labels):
    classList = [example[-1] for example in dataset]
    if classList.count(classList[0])==len(classList):
        return classList[0]
    if len(dataset[0])==1:
        return majorityCnt(classList)
    bestFeat = chooseBestFeatureToSplit(dataset)
    bestFeatLabel = labels[bestFeat]
    myTree = {bestFeatLabel:{}}
    del(labels[bestFeat])
    featValues = [example[bestFeat] for example in dataset]
    uniqueVals = set(featValues)
    for value in uniqueVals:
        subLables = labels[:]
        myTree[bestFeatLabel][value] = createTree(spiltDataset\
                                     (dataset,bestFeat,value),subLables)
    
    return myTree


if __name__ == '__main__':
    myDat,labels = createDataset()
    myTree = createTree(myDat,labels)
    print('myTree\n',myTree)