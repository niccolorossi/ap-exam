#!/usr/bin/env python
# coding: utf-8

# In[8]:

from datetime import datetime

class PostcardList:

    def __init__(self):
        """
        class initializer:
        _file is the file name (or path);
        _postcards is the list of postcards read from _file;
        _date is a dict: "date" string is key, each index refers to the corresponding record;
        _from is a dict: the sender name is key, each index refers to the corresponding record;
        _to is a dict: the receiver is key, each index refers to the corresponding record.
        """
        self._file = ""
        self._postcards = []
        self._date = {}
        self._from = {}
        self._to = {}


    def __iter__(self):
        """
        a function used for unpacking class members
        """
        return (i for i in (self._postcard, self._date, self._from, self._to))


    def __eq__(self, other):
        """
        a function used to assert equivalence between class instances
        """
        return tuple(self)==tuple(other)


    def writeFile(self, nomefile):
        """
        this function writes postcards to an outfile "nomefile"
        """
        self._file = nomefile
        out_file = open(self._file,"w")

        for i in self._postcards:
            out_file.write(i)

        out_file.close()


    def readFile(self, nomefile):
        """
        this function reads postcards from an outfile "nomefile"
        """

        self._file = nomefile
        out_file = open(nomefile, "r")
        self._postcards = out_file.readlines()
        out_file.close()
        self.parsePostcards()


    def parsePostcards(self):
        """
        this function updates the dictionaries with already stored postcards
        """
        j=0
        for i in self._postcards:
            d,f,t = i.split(" ")
            d = d[5:-1]
            d = datetime.strptime(d, "%Y-%m-%d")
            if d not in self._date:
                self._date[d] = []
            self._date[d].append(j)
            f = f[5:-1]
            if f not in self._from:
                self._from[f] = []
            self._from[f].append(j)
            t = t[3:-2]
            if t not in self._to:
                self._to[t] = []
            self._to[t].append(j)
            j=j+1


    def updateFile(self, nomefile):
        """
        this function appends postcards to an outfile "nomefile"
        """
        self._file = nomefile
        out_file = open(self._file,"a")

        for i in self._postcards:
            out_file.write(i)

        out_file.close()


    def updateLists(self, nomefile):
        """
        this function reads postcards from an outfile and appends them to
        self._postcards
        """
        self._file = nomefile
        out_file = open(nomefile, "r")
        self._postcards = out_file.readlines()
        out_file.close()
        self.parsePostcards()


    def getNumberOfPostcards(self):
        """
        this function returns the number of postcards read
        """
        return len(self._postcards)


    def getPostcardsByDateRange(self,date_range):
        """
        this function returns all the postcards within a given date_range
        """

        returned_postcards = []
        i = 0
        while i < len(self._postcards):
            d,f,t = self._postcards[i].split(" ")
            d = d[5:-1]
            d = datetime.strptime(d, "%Y-%m-%d")
            if (date_range[0] <= d <= date_range[1]):
                returned_postcards.append(self._postcards[i])
            i=i+1

        return returned_postcards


    def getPostcardsBySender(self, sender):
        """
        this function returns all the postcards from a given sender
        """
        returned_postcards = []
        i = 0
        while i < len(self._postcards):
            d,f,t = self._postcards[i].split(" ")
            f = f[5:-1]

            if f == sender:
                returned_postcards.append(self._postcards[i])
            i=i+1

        return returned_postcards


    def getPostcardsByReceiver(self, receiver):
        """
        this function returns all the postcards to a given receiver
        """

        returned_postcards = []
        i = 0
        while i < len(self._postcards):
            d,f,t = self._postcards[i].split(" ")
            t = t[3:-2]

            if t == receiver:
                returned_postcards.append(self._postcards[i])
            i=i+1

        return returned_postcards
