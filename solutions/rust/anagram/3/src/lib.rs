use std::collections::HashSet;

fn normalize_word(word: &str) -> Vec<char> {
    let mut normalized_word: Vec<char> = word.to_lowercase().chars().collect::<Vec<char>>();

    normalized_word.sort_unstable();
    normalized_word
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let mut anagrams = HashSet::new();
    let normalized_word = normalize_word(word);

    for possible_anagram in possible_anagrams {
        if normalized_word == normalize_word(possible_anagram)
            && word.to_lowercase() != possible_anagram.to_lowercase()
        {
            anagrams.insert(*possible_anagram);
        }
    }

    anagrams
}
