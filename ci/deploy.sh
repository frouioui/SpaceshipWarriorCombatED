#!/usr/bin/env sh

ssh-keyscan git.epitech.eu >> ~/.ssh/known_hosts
git checkout $TRAVIS_BRANCH
git push --repo=git@git.epitech.eu:/florent.poinsard@epitech.eu/CPP_rtype_2019 --force