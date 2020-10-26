def main():
    stop_words = input().split(';')
    index_terms = input().split(';')
    doc_as_string = ""
    counter_terms = {}
    total_words = 0

    for index_term in index_terms:
        counter_terms[index_term] = 0

    while True:
        try:
            doc_as_string += input() + ' '
        except EOFError:
            break

    doc_as_string = doc_as_string.lower().replace(',', '').replace(
        '.', '').replace('?', '').replace('!', '').replace(
            '>', '> ').replace('<', ' <').split()

    title = doc_as_string[doc_as_string.index(
        '<title>')+1:(doc_as_string.index('</title>'))]

    for word in title:
        if word not in stop_words and word[0] != '<' and len(word) >= 4:
            total_words += 1
            if word in index_terms:
                counter_terms[word] += 5

    abstract = doc_as_string[doc_as_string.index(
        '<abstract>')+1:(doc_as_string.index('</abstract>'))]

    for word in abstract:
        if word not in stop_words and word[0] != '<' and len(word) >= 4:
            total_words += 1
            if word in index_terms:
                counter_terms[word] += 3

    body = doc_as_string[doc_as_string.index(
        '<body>')+1:(doc_as_string.index('</body>'))]

    for word in body:
        if word not in stop_words and word[0] != '<' and len(word) >= 4:
            total_words += 1
            if word in index_terms:
                counter_terms[word] += 1

    sorted_elements = sorted(counter_terms.items(),
                             key=lambda a: a[1], reverse=True)

    result_dict = {}
    for element in sorted_elements:
        if element[1] in result_dict:
            result_dict[element[1]].append(element[0])
        else:
            result_dict[element[1]] = [element[0]]

    for element in list(result_dict.items())[: 3]:
        if element[0] > 0:
            w = sorted(element[1])
            density = element[0]/total_words*100
            for t in w:
                print('{}: {}'.format(t, density))


if __name__ == '__main__':
    main()
