use std::collections::HashSet;

fn normalize_word(word: &str) -> Vec<char> {
    let mut normalized_word: Vec<char> = word
        .to_lowercase()
        .chars()
        .collect::<Vec<char>>();

    normalized_word.sort_unstable();
    normalized_word
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let mut anagrams = HashSet::new();
    
    for possible_anagram in possible_anagrams {
        if normalize_word(word) == normalize_word(possible_anagram) {
            anagrams.insert(*possible_anagram);
        }
    }

    anagrams
}
