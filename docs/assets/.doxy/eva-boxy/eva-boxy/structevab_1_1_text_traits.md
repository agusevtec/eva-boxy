

# Struct evab::TextTraits



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**TextTraits**](structevab_1_1_text_traits.md)



_Traits for C-string (char\*)._ 

* `#include <evabTextTraits.h>`







































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Length**](#function-length-14) (const char \* aText) <br> |
|  unsigned char | [**Length**](#function-length-24) (char \* aText) <br> |
|  unsigned char | [**Length**](#function-length-34) (const \_\_FlashStringHelper \* aText) <br> |
|  unsigned char | [**Length**](#function-length-44) (\_\_FlashStringHelper \* aText) <br> |
|  char | [**Read**](#function-read-14) (const char \* aText, unsigned char aIndex) <br> |
|  char | [**Read**](#function-read-24) (char \* aText, unsigned char aIndex) <br> |
|  char | [**Read**](#function-read-34) (const \_\_FlashStringHelper \* aText, unsigned char aIndex) <br> |
|  char | [**Read**](#function-read-44) (\_\_FlashStringHelper \* aText, unsigned char aIndex) <br> |


























## Public Static Functions Documentation




### function Length [1/4]

```C++
static inline unsigned char evab::TextTraits::Length (
    const char * aText
) 
```




<hr>



### function Length [2/4]

```C++
static inline unsigned char evab::TextTraits::Length (
    char * aText
) 
```




<hr>



### function Length [3/4]

```C++
static inline unsigned char evab::TextTraits::Length (
    const __FlashStringHelper * aText
) 
```




<hr>



### function Length [4/4]

```C++
static inline unsigned char evab::TextTraits::Length (
    __FlashStringHelper * aText
) 
```




<hr>



### function Read [1/4]

```C++
static inline char evab::TextTraits::Read (
    const char * aText,
    unsigned char aIndex
) 
```




<hr>



### function Read [2/4]

```C++
static inline char evab::TextTraits::Read (
    char * aText,
    unsigned char aIndex
) 
```




<hr>



### function Read [3/4]

```C++
static inline char evab::TextTraits::Read (
    const __FlashStringHelper * aText,
    unsigned char aIndex
) 
```




<hr>



### function Read [4/4]

```C++
static inline char evab::TextTraits::Read (
    __FlashStringHelper * aText,
    unsigned char aIndex
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabTextTraits.h`

